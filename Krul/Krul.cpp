#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <vector>
#include <crtdbg.h>

#include "ContainerManager.h"
#include "Libcurl.h"
#include "OperationFactory.h"

std::unique_ptr<OperationFactory> operationFactory;

void start();
void krulSequence(ContainerManager& containerManager, std::string baseUrl, std::string appendUrl);

int main()
{
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// _CrtSetBreakAlloc(74333);

	try
	{
		start();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	catch(...)
	{
		std::cout << "An unknown exception occurred, stopping execution of application...";
	}
	
	_CrtDumpMemoryLeaks();
}

void start()
{
	operationFactory = std::make_unique<OperationFactory>();
	ContainerManager containerManager;
	krulSequence(containerManager, "https://www.swiftcoder.nl/cpp1/", "start.txt");
}

void krulSequence(ContainerManager& containerManager, std::string baseUrl, std::string appendUrl)
{
	std::istringstream response(makeCurlRequest(baseUrl + appendUrl));
	bool endIsHere = false;
	
	for (std::string line; std::getline(response, line); )
	{
		containerManager.raw.push_back(line);
	}

	// Index-based iteration
	for (int i = 0; i != containerManager.raw.size(); ++i)
	{
		if(containerManager.raw[i] == "end")
		{
			endIsHere = true;
			break;
		}
		
		std::string identifier = containerManager.raw[i];
		
		operationFactory->GetOperation(identifier)->execute(identifier, i, containerManager);
	}

	// Print stack
	for (const std::string& i : containerManager.stack)
	{
		std::cout << i << '\n';
	}

	// Set new iteration data
	if(!endIsHere)
	{
		appendUrl = containerManager.stack.back();
		containerManager.clearContainers();
		krulSequence(containerManager, baseUrl, appendUrl);
	}
}
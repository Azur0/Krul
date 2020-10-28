#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <vector>
#include <crtdbg.h>

#include "ContainerManager.h"
#include "Libcurl.h"
#include "OperationFactory.h"

const std::string baseURL = "https://www.swiftcoder.nl/cpp1/";
std::string appendURL = "start.txt";

void start();
void initializeOperationFactory();
void krulSequence(ContainerManager& containerManager);

int main()
{
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// _CrtSetBreakAlloc(74333);

	start();
	
	_CrtDumpMemoryLeaks();
}

void start()
{
	ContainerManager containerManager;
	krulSequence(containerManager);
}

void krulSequence(ContainerManager& containerManager)
{
	std::istringstream response(makeCurlRequest(baseURL + appendURL));
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
		
		OperationFactory::GetInstance().GetOperation(identifier)->execute(identifier, i, containerManager);
	}

	// Print stack
	for (const std::string& i : containerManager.stack)
	{
		std::cout << i << '\n';
	}

	// Set new iteration data
	if(!endIsHere)
	{
		appendURL = containerManager.stack.back();
		containerManager.clearContainers();
		krulSequence(containerManager);
	}
}
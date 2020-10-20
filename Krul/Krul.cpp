#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <vector>

#include "Duplicate.h"
#include "Concatenate.h"
#include "ContainerManager.h"
#include "Decrement.h"
#include "GotoNe.h"
#include "Libcurl.h"
#include "OperationFactory.h"
#include "Insert.h"
#include "TextEOL.h"
#include "LabelDefinition.h"
#include "LabelReference.h"
#include "VariableAssignment.h"
#include "VariableReference.h"

const std::string baseURL = "https://www.swiftcoder.nl/cpp1/";
std::string appendURL = "start.txt";

void initializeOperationFactory();
void krulSequence(ContainerManager& containerManager);

int main()
{
	ContainerManager containerManager;
	initializeOperationFactory();
	
	krulSequence(containerManager);
}

void krulSequence(ContainerManager& containerManager)
{
	std::istringstream response(makeCurlRequest(baseURL + appendURL));
	
	for (std::string line; std::getline(response, line); )
	{
		containerManager.raw.push_back(line);
	}

	// Index-based iteration
	for (int i = 0; i != containerManager.raw.size(); ++i)
	{
		// Special character check
		if (containerManager.raw[i].at(0) == '\\' || containerManager.raw[i].at(0) == ':' || containerManager.raw[i].at(0) == '>' || containerManager.raw[i].at(0) == '+' || containerManager.raw[i].at(0) == '=' || containerManager.raw[i].at(0) == '$' || std::regex_match(containerManager.raw[i], std::regex("\\d+(neg)?$")))
		{
			if (std::regex_match(containerManager.raw[i], std::regex("\\d+(neg)?$")))
			{
				OperationFactory::GetInstance().GetOperation("insert")->execute(containerManager.raw[i], i, containerManager);
			}
			else
			{
				OperationFactory::GetInstance().GetOperation(std::string(1, containerManager.raw[i].at(0)))->execute(containerManager.raw[i], i, containerManager);
			}
		}
		else
		{
			OperationFactory::GetInstance().GetOperation(containerManager.raw[i])->execute(containerManager.raw[i], i, containerManager);
		}
	}

	// Print stack
	for (const std::string& i : containerManager.stack)
	{
		std::cout << i << '\n';
	}

	if(containerManager.raw.back() == "end")
	{
		;
	}
	else
	{
		// Set new iteration data
		appendURL = containerManager.stack.back();
		containerManager.clearContainers();
		krulSequence(containerManager);
	}
}

void initializeOperationFactory()
{
	// Basic operations
	OperationFactory::GetInstance().RegisterOperation(new Insert, "insert");
	
	// Values & Types
	OperationFactory::GetInstance().RegisterOperation(new TextEOL, "\\");
	OperationFactory::GetInstance().RegisterOperation(new LabelDefinition, ":");
	OperationFactory::GetInstance().RegisterOperation(new LabelReference, ">");
	OperationFactory::GetInstance().RegisterOperation(new VariableAssignment, "=");
	OperationFactory::GetInstance().RegisterOperation(new VariableReference, "$");

	// Integer operations
	OperationFactory::GetInstance().RegisterOperation(new Decrement, "dec");

	// String operations
	OperationFactory::GetInstance().RegisterOperation(new Duplicate, "dup");
	OperationFactory::GetInstance().RegisterOperation(new Concatenate, "cat");

	// Tests & Jumps
	OperationFactory::GetInstance().RegisterOperation(new GotoNe, "gne");
}
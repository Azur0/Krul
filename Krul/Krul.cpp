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

std::vector<std::string> raw;
std::vector<std::string> stack;
std::map<std::string, int> labels;
std::map<std::string, std::string> variables;

void initializeOperationFactory();

int main()
{
	initializeOperationFactory();

	ContainerManager containerManager;
	
	std::string baseURL = "https://www.swiftcoder.nl/cpp1/start.txt";
	std::istringstream response(makeCurlRequest(baseURL));

	for (std::string line; std::getline(response, line); )
	{
		raw.push_back(line);
	}

	// Index-based iteration
	for(std::size_t i = 0; i != raw.size(); ++i)
	{
		// Special character check
		if (raw[i].at(0) == '\\' || raw[i].at(0) == ':' || raw[i].at(0) == '>' || raw[i].at(0) == '+' || raw[i].at(0) == '=' || raw[i].at(0) == '$' || std::regex_match(raw[i], std::regex("\\d+(neg)?$")))
		{
			if (std::regex_match(raw[i], std::regex("\\d+(neg)?$")))
			{
				OperationFactory::GetInstance().GetOperation("insert")->execute(raw[i], raw, stack, labels, variables);
			}
			else
			{
				OperationFactory::GetInstance().GetOperation(std::string(1, raw[i].at(0)))->execute(raw[i], raw, stack, labels, variables);
			}
		}
		else
		{
			OperationFactory::GetInstance().GetOperation(raw[i])->execute(raw[i], raw, stack, labels, variables);
		}
	}

	// Print stack
	for (const std::string& i : stack)
	{
		std::cout << i << '\n';
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
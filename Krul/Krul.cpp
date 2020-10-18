#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include "Libcurl.h"
#include "OperationFactory.h"
#include "TextEOL.h"
#include "LabelDefinition.h"

std::vector<std::string> raw;
std::vector<std::string> stack;
std::map<std::string, int> labels;
std::map<std::string, std::string> variables;

void initializeOperationFactory();

int main()
{
	initializeOperationFactory();
	
	std::string baseURL = "https://www.swiftcoder.nl/cpp1/start.txt";
	std::istringstream response(makeCurlRequest(baseURL));

	for (std::string line; std::getline(response, line); )
	{
		raw.push_back(line);
	}
	
	int counter = 0;
	for (const std::string& line : raw)
	{
		OperationFactory::GetInstance().GetOperation("\\")->execute(line, raw, stack, labels, variables);
	}

	// Print stack
	for (const std::string& i : stack)
	{
		std::cout << i << '\n';
	}
}

void initializeOperationFactory()
{
	// Values & Types
	OperationFactory::GetInstance().RegisterOperation(new TextEOL, "\\");
	OperationFactory::GetInstance().RegisterOperation(new LabelDefinition, ":");
	OperationFactory::GetInstance().RegisterOperation(new LabelDefinition, ">");
	OperationFactory::GetInstance().RegisterOperation(new LabelDefinition, "=");
	OperationFactory::GetInstance().RegisterOperation(new LabelDefinition, "$");

	// Integer operations
}
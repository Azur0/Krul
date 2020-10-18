#include "Operations.h"

// Values & Types
void textTEOL(std::string value, std::vector<std::string>& stack)
{
	value.erase(0, 1);
	stack.push_back(value);
}

void labelDefinition(std::string value, int position, std::map<std::string, int>& labels)
{
	value.erase(0, 1);
	labels[value] = position + 1;
}

void labelReference(std::string value, std::vector<std::string>& stack, std::map<std::string, int>& labels)
{
	/*value.erase(0, 1);
	std::string test = stack.at(labels[value]);*/
}

void varAssign()
{
	
}
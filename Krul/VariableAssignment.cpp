#include "VariableAssignment.h"

void VariableAssignment::execute(std::string value, std::vector<std::string>& raw, std::vector<std::string>& stack, std::map<std::string, int>& labels, std::map<std::string, std::string>& variables)
{
	value.erase(0, 1);
	variables[value] = stack.back();
	stack.pop_back();
}
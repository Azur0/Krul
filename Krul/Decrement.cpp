#include "Decrement.h"

#include <string>

void Decrement::execute(std::string value, std::vector<std::string>& raw, std::vector<std::string>& stack, std::map<std::string, int>& labels, std::map<std::string, std::string>& variables)
{
	int decrementedNumber = std::stoi(stack.back()) - 1;
	stack.push_back(std::to_string(decrementedNumber));
}

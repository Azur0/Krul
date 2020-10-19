#include "Concatenate.h"

void Concatenate::execute(std::string value, std::vector<std::string>& raw, std::vector<std::string>& stack, std::map<std::string, int>& labels, std::map<std::string, std::string>& variables)
{
	std::string concatenatedString = stack.back() + stack.end()[-2];
	stack.push_back(concatenatedString);
}
#include "Operation.h"
#include "TextEOL.h"

void TextEOL::execute(std::string value, std::vector<std::string>& raw, std::vector<std::string>& stack, std::map<std::string, int>& labels, std::map<std::string, std::string>& variables)
{
	value.erase(0, 1);
	stack.push_back(value);
}
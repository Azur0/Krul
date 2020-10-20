#include "Operation.h"
#include "TextEOL.h"

void TextEOL::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	value.erase(0, 1);
	containerManager.stack.push_back(value);
}
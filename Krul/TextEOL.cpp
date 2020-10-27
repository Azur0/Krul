#include "Operation.h"
#include "TextEOL.h"

void TextEOL::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	containerManager.stack.push_back(value);
}
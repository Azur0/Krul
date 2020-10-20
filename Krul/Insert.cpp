#include "Insert.h"

void Insert::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	containerManager.stack.push_back(value);
}
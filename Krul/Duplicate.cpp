#include "Duplicate.h"

void Duplicate::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	containerManager.stack.push_back(containerManager.stack.back());
}
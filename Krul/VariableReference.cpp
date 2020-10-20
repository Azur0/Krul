#include "VariableReference.h"

void VariableReference::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	value.erase(0, 1);
	containerManager.stack.push_back(containerManager.variables[value]);
}
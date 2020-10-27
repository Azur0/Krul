#include "VariableReference.h"

void VariableReference::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	containerManager.stack.push_back(containerManager.variables[value]);
}
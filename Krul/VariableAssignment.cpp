#include "VariableAssignment.h"

void VariableAssignment::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	containerManager.variables[value] = containerManager.stack.back();
	containerManager.stack.pop_back();
}
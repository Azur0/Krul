#include "VariableAssignment.h"

void VariableAssignment::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	value.erase(0, 1);
	containerManager.variables[value] = containerManager.stack.back();
	containerManager.stack.pop_back();
}
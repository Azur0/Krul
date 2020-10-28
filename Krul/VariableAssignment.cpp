#include "VariableAssignment.h"

void VariableAssignment::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if (containerManager.stack.size() == 0)
	{
		std::cout << "Operation: " + value + " failed, no elements available in container.";

		return;
	}
	
	containerManager.variables[value] = containerManager.stack.back();
	containerManager.stack.pop_back();
}
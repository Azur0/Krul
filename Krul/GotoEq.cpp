#include "GotoEq.h"

void GotoEq::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int labelIndex = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();

	std::string value1 = containerManager.stack.back();
	containerManager.stack.pop_back();

	std::string value2 = containerManager.stack.back();
	containerManager.stack.pop_back();

	if (value1 == value2)
		iterator = labelIndex - 1;
}

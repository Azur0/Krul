#include "GotoGt.h"

void GotoGt::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int labelIndex = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();

	int value2 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();

	int value1 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();

	if (value1 > value2)
		iterator = labelIndex - 1;
}

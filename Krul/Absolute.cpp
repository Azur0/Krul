#include "Absolute.h"

#include <string>

void Absolute::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int number = abs(Utility::parseInt(containerManager.stack.back()));

	containerManager.stack.pop_back();

	containerManager.stack.push_back(Utility::toString(number));
}

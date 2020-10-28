#include "Negate.h"

#include <string>

void Negate::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	const int number = Utility::parseInt(containerManager.stack.back()) * -1;

	containerManager.stack.pop_back();

	containerManager.stack.push_back(Utility::toString(number));
}

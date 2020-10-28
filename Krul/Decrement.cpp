#include "Decrement.h"

#include <string>

void Decrement::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if (containerManager.stack.size() == 0)
	{
		std::cout << "Operation: " + value + " failed, no elements available in container.";

		return;
	}
	
	const int number = Utility::parseInt(containerManager.stack.back()) - 1;

	containerManager.stack.pop_back();
	
	containerManager.stack.push_back(Utility::toString(number));
}

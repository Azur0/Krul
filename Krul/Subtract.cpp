#include "Subtract.h"

#include <string>

void Subtract::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if (containerManager.stack.size() == 0)
	{
		std::cout << "Operation: " + value + " failed, no elements available in container.";

		return;
	}
	
	const int number1 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	const int number2 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	const int result = number2 - number1;

	containerManager.stack.push_back(Utility::toString(result));
}

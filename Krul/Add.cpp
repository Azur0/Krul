#include "Add.h"

#include <string>

void Add::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int number1 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	int number2 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	int result = number1 + number2;

	containerManager.stack.push_back(Utility::toString(result));
}

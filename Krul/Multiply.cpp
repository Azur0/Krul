#include "Multiply.h"

#include <string>

void Multiply::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	const int number1 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	const int number2 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	const int result = number1 * number2;

	containerManager.stack.push_back(Utility::toString(result));
}

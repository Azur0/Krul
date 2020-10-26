#include "Multiply.h"

#include <string>

void Multiply::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int number1 = Utility::parseInt(containerManager.stack.end()[-1]);
	int number2 = Utility::parseInt(containerManager.stack.end()[-2]);
	int result = number1 * number2;

	containerManager.stack.pop_back();
	containerManager.stack.pop_back();

	containerManager.stack.push_back(Utility::toString(result));
}

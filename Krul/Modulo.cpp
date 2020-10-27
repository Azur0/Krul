#include "Modulo.h"

#include <string>

void Modulo::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int number1 = Utility::parseInt(containerManager.stack.end()[-1]);
	int number2 = Utility::parseInt(containerManager.stack.end()[-2]);
	int result = number2 % number1;

	containerManager.stack.pop_back();
	containerManager.stack.pop_back();

	containerManager.stack.push_back(Utility::toString(result));
}
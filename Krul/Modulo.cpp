#include "Modulo.h"

#include <string>

void Modulo::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int number1 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	int number2 = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	int result = number2 % number1;

	containerManager.stack.push_back(Utility::toString(result));
}

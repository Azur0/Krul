#include "Decrement.h"

#include <string>

void Decrement::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int decrementedNumber = std::stoi(containerManager.stack.end()[-1]) - 1;

	containerManager.stack.pop_back();
	
	containerManager.stack.push_back(std::to_string(decrementedNumber));
}

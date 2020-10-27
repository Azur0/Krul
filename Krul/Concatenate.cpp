#include "Concatenate.h"

void Concatenate::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string value1 = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	std::string value2 = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	std::string concatenatedString = value2 + value1;

	containerManager.stack.push_back(concatenatedString);
}
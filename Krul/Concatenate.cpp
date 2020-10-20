#include "Concatenate.h"

void Concatenate::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string concatenatedString = containerManager.stack.end()[-2] + containerManager.stack.end()[-1];

	containerManager.stack.pop_back();
	containerManager.stack.pop_back();
	
	containerManager.stack.push_back(concatenatedString);
}
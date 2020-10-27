#include "Reverse.h"

void Reverse::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string string = containerManager.stack.back();
	containerManager.stack.pop_back();

	std::reverse(string.begin(), string.end());
	
	containerManager.stack.push_back(string);
}
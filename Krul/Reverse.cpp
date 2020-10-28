#include "Reverse.h"

void Reverse::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if (containerManager.stack.size() == 0)
	{
		std::cout << "Operation: " + value + " failed, no elements available in container.";

		return;
	}
	
	std::string string = containerManager.stack.back();
	containerManager.stack.pop_back();

	std::reverse(string.begin(), string.end());
	
	containerManager.stack.push_back(string);
}
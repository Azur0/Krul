#include "Concatenate.h"

void Concatenate::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if (containerManager.stack.size() == 0)
	{
		std::cout << "Operation: " + value + " failed, no elements available in container.";

		return;
	}
	
	const std::string value1 = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	const std::string value2 = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	const std::string concatenatedString = value2 + value1;

	containerManager.stack.push_back(concatenatedString);
}
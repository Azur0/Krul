#include "Index.h"

void Index::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int index = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	std::string currentValue = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	std::string result = std::string(1, currentValue.at(index));

	containerManager.stack.push_back(result);
}
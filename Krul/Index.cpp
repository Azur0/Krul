#include "Index.h"

void Index::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	const int index = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	const std::string currentValue = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	const std::string result = std::string(1, currentValue.at(index));

	containerManager.stack.push_back(result);
}
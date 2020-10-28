#include "Index.h"

void Index::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if (containerManager.stack.size() == 0)
	{
		std::cout << "Operation: " + value + " failed, no elements available in container.";

		return;
	}
	
	const int index = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	const std::string currentValue = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	const std::string result = std::string(1, currentValue.at(index));

	containerManager.stack.push_back(result);
}
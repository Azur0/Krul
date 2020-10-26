#include "Index.h"

void Index::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int index = Utility::parseInt(containerManager.stack.end()[-1]);
	std::string value = containerManager.stack.end()[-2];
	std::string result = std::string(1, value.at(index));

	containerManager.stack.pop_back();
	containerManager.stack.pop_back();

	containerManager.stack.push_back(result);
}
#include "Length.h"

void Length::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string string = containerManager.stack.end()[-1];
	std::string result = std::to_string(string.length());

	containerManager.stack.pop_back();

	containerManager.stack.push_back(result);
}
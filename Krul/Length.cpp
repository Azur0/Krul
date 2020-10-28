#include "Length.h"

void Length::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	const std::string value1 = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	const std::string result = std::to_string(value1.length());

	containerManager.stack.push_back(result);
}
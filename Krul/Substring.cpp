#include "Substring.h"

void Substring::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	const int to = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	const int from = Utility::parseInt(containerManager.stack.back());
	containerManager.stack.pop_back();
	
	const std::string currentValue = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	const std::string result = currentValue.substr(from, to - from);

	containerManager.stack.push_back(result);
}
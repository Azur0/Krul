#include "Substring.h"

void Substring::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int to = Utility::parseInt(containerManager.stack.end()[-1]);
	int from = Utility::parseInt(containerManager.stack.end()[-2]);
	std::string value = containerManager.stack.end()[-3];
	std::string result = value.substr(from, to - 1);
	
	containerManager.stack.pop_back();
	containerManager.stack.pop_back();
	containerManager.stack.pop_back();

	containerManager.stack.push_back(result);
}
#include "Newline.h"

void Newline::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string string = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	string.append("\n");

	containerManager.stack.push_back(string);
}
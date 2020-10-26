#include "Newline.h"

void Newline::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string string = containerManager.stack.end()[-1];

	string.append("\n");

	containerManager.stack.pop_back();

	containerManager.stack.push_back(string);
}
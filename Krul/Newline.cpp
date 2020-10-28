#include "Newline.h"

void Newline::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if (containerManager.stack.size() == 0)
	{
		std::cout << "Operation: " + value + " failed, no elements available in container.";

		return;
	}
	
	std::string string = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	string.append("\n");

	containerManager.stack.push_back(string);
}
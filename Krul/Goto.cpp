#include "Goto.h"

void Goto::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string value1 = containerManager.stack.back();
	containerManager.stack.pop_back();
	
	iterator = Utility::parseInt(value1) - 1;
}

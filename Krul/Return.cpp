#include "Return.h"

void Return::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int index = containerManager.callstack.back();
	containerManager.callstack.pop_back();

	iterator = index - 1;
}

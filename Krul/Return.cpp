#include "Return.h"

void Return::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if(containerManager.callstack.size() == 0)
	{
		std::cout << "Operation: " + value + " failed, no elements available in container.";
		
		return;
	}
	
	int index = containerManager.callstack.back();
	containerManager.callstack.pop_back();

	iterator = index - 1;
}

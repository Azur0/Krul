#include "ContainerManager.h"

void ContainerManager::clearContainers()
{
	raw.clear();
	stack.clear();
	callstack.clear();
	labels.clear();
	variables.clear();
}

bool ContainerManager::containsLabelReference(std::string labelReference)
{
	auto it = labels.find(labelReference);
	
	if(it != labels.end())
	{
		return true;
	}

	return false;
}
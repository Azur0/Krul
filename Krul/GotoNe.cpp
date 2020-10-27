#include "GotoNe.h"

void GotoNe::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string value1 = containerManager.stack.end()[-2];
	std::string value2 = containerManager.stack.end()[-3];
	
	if (value1 != value2)
	{
		std::vector<std::string>::iterator it = std::find(containerManager.raw.begin(), containerManager.raw.end(), value);

		int labelIndex = std::distance(containerManager.raw.begin(), it) - 1;
		std::string labelValue = containerManager.raw.at(labelIndex);

		iterator = containerManager.labels[labelValue.erase(0, 1)] - 1;
	}

	containerManager.stack.pop_back();
	containerManager.stack.pop_back();
	containerManager.stack.pop_back();
}

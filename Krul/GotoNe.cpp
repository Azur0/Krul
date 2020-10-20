#include "GotoNe.h"

void GotoNe::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	auto x = containerManager.stack.end()[-2];
	auto y = containerManager.stack.end()[-3];
	
	if (containerManager.stack.end()[-2] != containerManager.stack.end()[-3])
	{
		std::vector<std::string>::iterator it = std::find(containerManager.raw.begin(), containerManager.raw.end(), value);

		int labelIndex = std::distance(containerManager.raw.begin(), it) - 1;
		std::string labelValue = containerManager.raw.at(labelIndex);

		int val1 = labelIndex;

		iterator = containerManager.labels[labelValue.erase(0, 1)] - 1;
	}
}

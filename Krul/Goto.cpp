#include "Goto.h"

void Goto::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string value1 = containerManager.stack.back();

	//std::vector<std::string>::iterator it = std::find(containerManager.raw.begin(), containerManager.raw.end(), value1);
	//
	//int labelIndex = std::distance(containerManager.raw.begin(), it) - 1;
	//std::string labelValue = containerManager.raw.at(labelIndex);

	//iterator = containerManager.labels[labelValue.erase(0, 1)] - 1;

	iterator = Utility::parseInt(value1) - 1;

	containerManager.stack.pop_back();
}

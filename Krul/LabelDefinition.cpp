#include "LabelDefinition.h"

void LabelDefinition::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string label = ":" + value;
	std::vector<std::string>::iterator it = std::find(containerManager.raw.begin(), containerManager.raw.end(), label);

	if(it != containerManager.raw.end())
		containerManager.labels[value] = std::distance(containerManager.raw.begin(), it) + 1;
}
#include "LabelDefinition.h"

void LabelDefinition::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::vector<std::string>::iterator it = std::find(containerManager.raw.begin(), containerManager.raw.end(), value);

	if(it != containerManager.raw.end())
		value.erase(0, 1);
		containerManager.labels[value] = std::distance(containerManager.raw.begin(), it) + 1;
}
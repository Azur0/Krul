#include "LabelDefinition.h"

void LabelDefinition::execute(std::string value, std::vector<std::string>& raw, std::vector<std::string>& stack, std::map<std::string, int>& labels, std::map<std::string, std::string>& variables)
{
	std::vector<std::string>::iterator it = std::find(raw.begin(), raw.end(), value);

	if(it != raw.end())
		value.erase(0, 1);
		labels[value] = std::distance(raw.begin(), it) + 1;
}
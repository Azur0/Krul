#include "LabelReference.h"

#include <regex>


#include "OperationFactory.h"

void LabelReference::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	value.erase(0, 1);
	std::string referencedValue = containerManager.raw.at(containerManager.labels.find(value)->second);
	
	if (referencedValue.at(0) == '\\' || referencedValue.at(0) == ':' || referencedValue.at(0) == '>' || referencedValue.at(0) == '+' || referencedValue.at(0) == '=' || referencedValue.at(0) == '$' || std::regex_match(referencedValue, std::regex("\\d+(neg)?$")))
	{
		if (std::regex_match(referencedValue, std::regex("\\d+(neg)?$")))
		{
			OperationFactory::GetInstance().GetOperation("insert")->execute(referencedValue, iterator, containerManager);
		}
		else
		{
			OperationFactory::GetInstance().GetOperation(std::string(1, referencedValue.at(0)))->execute(referencedValue, iterator, containerManager);
		}
	}
	else
	{
		OperationFactory::GetInstance().GetOperation(referencedValue)->execute(referencedValue, iterator, containerManager);
	}
}

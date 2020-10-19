#include "LabelReference.h"

#include <regex>


#include "OperationFactory.h"

void LabelReference::execute(std::string value, std::vector<std::string>& raw, std::vector<std::string>& stack, std::map<std::string, int>& labels, std::map<std::string, std::string>& variables)
{
	value.erase(0, 1);
	std::string referencedValue = raw.at(labels.find(value)->second);
	
	if (referencedValue.at(0) == '\\' || referencedValue.at(0) == ':' || referencedValue.at(0) == '>' || referencedValue.at(0) == '+' || referencedValue.at(0) == '=' || referencedValue.at(0) == '$' || std::regex_match(referencedValue, std::regex("\\d+(neg)?$")))
	{
		if (std::regex_match(referencedValue, std::regex("\\d+(neg)?$")))
		{
			OperationFactory::GetInstance().GetOperation("insert")->execute(referencedValue, raw, stack, labels, variables);
		}
		else
		{
			OperationFactory::GetInstance().GetOperation(std::string(1, referencedValue.at(0)))->execute(referencedValue, raw, stack, labels, variables);
		}
	}
	else
	{
		OperationFactory::GetInstance().GetOperation(referencedValue)->execute(referencedValue, raw, stack, labels, variables);
	}
}

#include "OperationFactory.h"

OperationFactory OperationFactory::instance;

void OperationFactory::RegisterOperation(std::shared_ptr<Operation> operation, std::string operationIdentifier)
{
	registeredOperations[operationIdentifier] = operation;
}

std::shared_ptr<Operation> OperationFactory::GetOperation(std::string& operationIdentifier)
{
	const std::string identifier = this->getOperationIdentifier(operationIdentifier);

	// Nullptr if operation does not exist
	if(registeredOperations.count(identifier) == 0)
	{
		return nullptr;
	}
	
	return registeredOperations[identifier];
}

std::string OperationFactory::getOperationIdentifier(std::string& value)
{
	if (Utility::isSpecialCharacter(value.at(0)))
	{
		std::string identifier = std::string(1, value.at(0));
		value.erase(value.begin());
		return identifier;
	}
	else if (Utility::isNumeric(value))
	{
		return "insert";
	}

	return value;
}
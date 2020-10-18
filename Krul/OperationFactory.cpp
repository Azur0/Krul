#include "OperationFactory.h"

OperationFactory OperationFactory::instance;

void OperationFactory::RegisterOperation(Operation* Operation, std::string OperationIdentifier)
{
	registeredOperations[OperationIdentifier] = Operation;
}

Operation* OperationFactory::GetOperation(std::string OperationIdentifier)
{
	return registeredOperations[OperationIdentifier];
}
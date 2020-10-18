#pragma once
#include <map>
#include <string>
#include "Operation.h"

class OperationFactory
{
public:
	static OperationFactory& GetInstance() { return instance; }

	// Rule of five
	OperationFactory(const OperationFactory&) = delete;
	OperationFactory(OperationFactory&&) = delete;
	OperationFactory& operator=(const OperationFactory&) = delete;
	OperationFactory& operator=(OperationFactory&&) = delete;

	void RegisterOperation(Operation* Operation, std::string OperationIdentifier);
	Operation* GetOperation(std::string OperationIdentifier);

private:
	static OperationFactory instance;
	std::map<std::string, Operation*> registeredOperations;

	OperationFactory() {}
};

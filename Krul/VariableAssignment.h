#pragma once
#include "Operation.h"

class VariableAssignment : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
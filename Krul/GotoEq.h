#pragma once
#include "Operation.h"

class GotoEq : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
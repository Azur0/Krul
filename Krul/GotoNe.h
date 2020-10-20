#pragma once
#include "Operation.h"

class GotoNe : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
#pragma once
#include "Operation.h"

class GotoGe : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
#pragma once
#include "Operation.h"

class GotoGt : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
#pragma once
#include "Operation.h"

class Multiply : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
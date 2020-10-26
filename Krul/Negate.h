#pragma once
#include "Operation.h"

class Negate : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
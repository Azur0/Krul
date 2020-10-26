#pragma once
#include "Operation.h"

class Absolute : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
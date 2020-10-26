#pragma once
#include "Operation.h"

class Add : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
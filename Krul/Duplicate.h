#pragma once
#include "Operation.h"

class Duplicate : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
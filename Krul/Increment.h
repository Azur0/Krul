#pragma once
#include "Operation.h"

class Increment : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
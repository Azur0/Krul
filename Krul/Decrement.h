#pragma once
#include "Operation.h"

class Decrement : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
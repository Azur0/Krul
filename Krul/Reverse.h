#pragma once
#include "Operation.h"

class Reverse : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
#pragma once
#include "Operation.h"

class Insert : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
#pragma once
#include "Operation.h"

class Return : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
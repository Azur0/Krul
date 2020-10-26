#pragma once
#include "Operation.h"

class Length : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
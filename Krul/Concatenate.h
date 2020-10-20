#pragma once
#include "Operation.h"

class Concatenate : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
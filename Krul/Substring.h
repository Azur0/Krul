#pragma once
#include "Operation.h"

class Substring : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
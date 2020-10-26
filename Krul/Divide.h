#pragma once
#include "Operation.h"

class Divide : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
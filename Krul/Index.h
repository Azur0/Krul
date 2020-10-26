#pragma once
#include "Operation.h"

class Index : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
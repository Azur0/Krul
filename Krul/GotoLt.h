#pragma once
#include "Operation.h"

class GotoLt : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
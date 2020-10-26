#pragma once
#include "Operation.h"

class Newline : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
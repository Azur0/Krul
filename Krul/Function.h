#pragma once
#include "Operation.h"

class Function : public Operation
{
public:
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
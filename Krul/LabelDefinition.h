#pragma once
#include "Operation.h"

class LabelDefinition : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
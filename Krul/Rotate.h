#pragma once
#include "Operation.h"
#define IsBigLetter(a) a >= 'A' && a <= 'Z'
#define IsSmallLetter(a) a >= 'a' && a <= 'z'

class Rotate : public Operation
{
	void execute(std::string value, int& iterator, ContainerManager& containerManager) override;
};
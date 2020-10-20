#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "ContainerManager.h"

class Operation
{
public:
	virtual void execute(std::string value, int& iterator, ContainerManager& containerManager) = 0;
};

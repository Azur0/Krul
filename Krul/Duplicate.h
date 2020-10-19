#pragma once
#include "Operation.h"

class Duplicate : public Operation
{
	void execute(std::string value, std::vector<std::string>& raw, std::vector<std::string>& stack, std::map<std::string, int>& labels, std::map<std::string, std::string>& variables) override;
};
#pragma once
#include <iostream>
#include <map>
#include <vector>

class Operation
{
public:
	virtual void execute(std::string value, std::vector<std::string>& raw, std::vector<std::string>& stack, std::map<std::string, int>& labels, std::map<std::string, std::string>& variables) = 0;
};

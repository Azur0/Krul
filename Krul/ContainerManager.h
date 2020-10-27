#pragma once
#include <map>
#include <string>
#include <vector>

class ContainerManager
{
public:
	std::vector<std::string> raw;
	std::vector<std::string> stack;
	std::vector<int> callstack;
	std::map<std::string, int> labels;
	std::map<std::string, std::string> variables;

	void clearContainers();
	bool containsLabelReference(std::string labelReference);
};
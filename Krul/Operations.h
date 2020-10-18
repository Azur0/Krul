#pragma once
#include <map>
#include <string>
#include <vector>

void textTEOL(std::string value, std::vector<std::string>& stack);
void labelDefinition(std::string value, int position, std::map<std::string, int>& labels);
void labelReference(std::string value, std::vector<std::string>& stack, std::map<std::string, int>& labels);
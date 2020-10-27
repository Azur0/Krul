#pragma once
#include <string>

class Utility
{
public:
	static int parseInt(const std::string& value);
	static std::string toString(const int& value);
	static std::string toString(const float& value);
	static bool isSpecialCharacter(const char& value);
	static bool isNumeric(const std::string& value);
};
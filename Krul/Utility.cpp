#include "Utility.h"

#include <regex>

int Utility::parseInt(const std::string& value)
{
    std::string number = value;
	
    if (value.find("neg") != std::string::npos)
    {
        number.erase(number.find("neg"));
        number.insert(0, "-");
    }

    return std::stoi(number);
}

std::string Utility::toString(const int& value)
{
    if (value < 0)
    {
        std::string string_value = std::to_string(std::abs(value));
        return string_value.append("neg");
    }
	
    return std::to_string(value);
}

std::string Utility::toString(const float& value)
{
    if (value < 0)
    {
        std::string string_value = std::to_string(std::abs(value));
        return string_value.append("neg");
    }
	
    return std::to_string(value);
}

bool Utility::isSpecialCharacter(const char& value)
{
    if ((value >= 65 && value <= 90) || (value >= 97 && value <= 122))
    {
        return false;
    }
    else if (value >= 48 && value <= 57)
    {
        return false;
    }
    return true;
}

bool Utility::isNumeric(const std::string& value)
{
    return std::regex_match(value, std::regex("\\d+(neg)?$"));
}
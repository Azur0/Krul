#include "Utility.h"

int Utility::parseInt(const std::string& value)
{
    std::string number_string = value;
    if (value.find("neg") != std::string::npos)
    {
        number_string.erase(number_string.find("neg"));
        number_string.insert(0, "-");
    }

    return std::stoi(number_string);
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
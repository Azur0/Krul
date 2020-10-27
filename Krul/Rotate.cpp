#include "Rotate.h"

void Rotate::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string string = containerManager.stack.back();
	containerManager.stack.pop_back();
	
    std::string result;
    for (char a : string)
    {
        if (IsBigLetter(a))
            result += ((int)a - (int)'A' + 13) % 26 + 'A';
        else if (IsSmallLetter(a))
            result += ((int)a - (int)'a' + 13) % 26 + 'a';
        else
            result += a;
    }

	containerManager.stack.push_back(result);
}
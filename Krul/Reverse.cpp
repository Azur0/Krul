#include "Reverse.h"

void Reverse::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string string = containerManager.stack.end()[-1];
	int length = string.length();
	int n = length - 1;

	for(int i = 0; i < (length / 2); i++)
	{
		char temp = string[i];
		string[i] = string[n];
		string[n] = temp;
		n = n - 1;
	}

	containerManager.stack.pop_back();

	containerManager.stack.push_back(string);
}
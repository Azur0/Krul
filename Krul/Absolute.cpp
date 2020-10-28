#include "Absolute.h"

#include <string>

void Absolute::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if (containerManager.stack.size() == 0)
	{
		std::cout << "Operation: " + value + " failed, no elements available in container.";

		return;
	}

	try
	{
		const int number = abs(Utility::parseInt(containerManager.stack.back()));
		
		containerManager.stack.pop_back();

		containerManager.stack.push_back(Utility::toString(number));
	}
	catch(...)
	{
		std::cout << "An error occurred while trying to parse a string/integer variable";
	}
}

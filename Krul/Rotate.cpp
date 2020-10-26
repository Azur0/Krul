#include "Rotate.h"

void Rotate::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	std::string string = containerManager.stack.end()[-1];
	std::string result;

	for (size_t i = 0; i < string.size(); ++i) {
		if (isalpha(string[i])) {
			if ((tolower(string[i]) - 'a') < 14)
				result.append(1, string[i] + 13);
			else
				result.append(1, string[i] - 13);
		}
		else {
			result.append(1, string[i]);
		}
	}
	
	containerManager.stack.pop_back();

	containerManager.stack.push_back(result);
}
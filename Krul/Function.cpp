#include "Function.h"

#include "Goto.h"

void Function::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	int instructionIndex = iterator + 1;
	containerManager.callstack.push_back(instructionIndex);

	std::unique_ptr<Goto> gotoOperation(new Goto());
	gotoOperation->execute(value, iterator, containerManager);
}

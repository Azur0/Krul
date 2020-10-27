#include "LabelReference.h"
#include <regex>
#include "LabelDefinition.h"
#include "OperationFactory.h"

void LabelReference::execute(std::string value, int& iterator, ContainerManager& containerManager)
{
	if (!containerManager.containsLabelReference(value))
	{
		std::unique_ptr<LabelDefinition> labelDefinitionOperation(new LabelDefinition());
		labelDefinitionOperation->execute(value, iterator, containerManager);
	}

	int labelIndex = containerManager.labels.at(value);
	
	containerManager.stack.push_back(Utility::toString(labelIndex));
}

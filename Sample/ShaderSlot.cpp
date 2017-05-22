#include "ShaderSlot.h"

#include "ShaderNode.h"

using namespace Crystal::UI;

ImVec2 ShaderInputSlot::getPosition() const
{
	return parent->GetInputSlotPos(id);
}

ImVec2 ShaderOutputSlot::getPosition() const
{
	return parent->GetOutputSlotPos(id);
}
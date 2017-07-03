#include "ShaderSlot.h"

#include "ShaderNode.h"

using namespace Crystal::UI;

std::ostream& Crystal::UI::operator<<(std::ostream& stream, const ShaderInputSlot& slot)
{
	stream << slot.id << std::endl;
	return stream;
}

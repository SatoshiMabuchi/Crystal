#include "ShaderSlot.h"

#include "ShaderNode.h"

using namespace Crystal::UI;

namespace {
	static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
	static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
}

ImVec2 ShaderInputSlot::getPosition() const
{
	return parent->GetInputSlotPos(id);
}

void ShaderInputSlot::draw(ImDrawList* draw_list, ImVec2 offset)
{
	const float NODE_SLOT_RADIUS = 4.0f;
	draw_list->AddCircleFilled(offset + getPosition(), NODE_SLOT_RADIUS, ImColor(150, 150, 150, 150));
}

ImVec2 ShaderOutputSlot::getPosition() const
{
	return parent->GetOutputSlotPos(id);
}

void ShaderOutputSlot::draw(ImDrawList* draw_list, ImVec2 offset)
{
	const float NODE_SLOT_RADIUS = 4.0f;
	draw_list->AddCircleFilled(offset + getPosition(), NODE_SLOT_RADIUS, ImColor(150, 150, 150, 150));
}

#include "INode.h"

using namespace Crystal::UI;

namespace {
	static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
	static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
}

ImVec2 IInSlot::getPosition() const
{
	return parent->getPosition() + ImVec2(50, 0);
}

ImVec2 IOutSlot::getPosition() const
{
	return parent->getPosition() - ImVec2(50, 0);
}

void IInSlot::show(const ImVec2& pos, ImDrawList* drawList)
{
	const float NODE_SLOT_RADIUS = 4.0f;
	drawList->AddCircleFilled(pos, NODE_SLOT_RADIUS, ImColor(150, 150, 150, 150));
}

void IOutSlot::show(const ImVec2& pos, ImDrawList* drawList)
{
	const float NODE_SLOT_RADIUS = 4.0f;
	drawList->AddCircleFilled(pos, NODE_SLOT_RADIUS, ImColor(150, 150, 150, 150));
}

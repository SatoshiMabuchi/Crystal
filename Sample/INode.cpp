#include "INode.h"

using namespace Crystal::UI;

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

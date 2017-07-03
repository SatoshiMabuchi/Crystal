#include "INode.h"
#include "ImGuiExt.h"

using namespace Crystal::UI;

ImVec2 IInSlot::getPosition() const
{
	return parent->getPosition(); //- ImVec2(50, 0);
}

ImVec2 IOutSlot::getPosition() const
{
	return parent->getPosition() + ImVec2(parent->getSize().x, 0);
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

void ILink::show(ImDrawList* drawList, const ImVec2& offset)
{
	const auto& p1 = outSlot->getPosition() + offset;
	const auto& p2 = inSlot->getPosition() + offset;
	drawList->AddBezierCurve(p1, p1 + ImVec2(+50, 0), p2 + ImVec2(-50, 0), p2, ImColor(200, 200, 100), 3.0f);
}

#include "CameraNode.h"
#include <imgui.h>

using namespace Crystal::UI;

namespace {
	static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
	static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
}

void Matrix4dSlot::show(const ImVec2& pos, ImDrawList* drawList)
{
	const float NODE_SLOT_RADIUS = 4.0f;
	drawList->AddCircleFilled(pos, NODE_SLOT_RADIUS, ImColor(150, 150, 150, 150));
}

CameraNode::CameraNode(const int id, const std::string& name, const ImVec2& pos) :
	id(id),
	name(name),
	pos(pos)
{}


void CameraNode::show(ImDrawList* drawList, ImVec2 offset)
{
	drawList->AddRectFilled(pos + offset, pos + offset + ImVec2(100, 100), ImColor(60, 60, 60), 4.0f);

	projectionMatrixSlot.show(offset + pos + ImVec2(100,0), drawList);
	modelviewMatrixSlot.show(offset + pos + ImVec2(100, 10), drawList);
	//drawList->AddCircleFilled(offset + ImVec2(10, 10), 10, ImColor(255, 100, 100, 100));

	/*
	ImGui::PushID(this->id);

	ImGui::Button(name.c_str(), ImVec2(100, 100));
	static float eyePosition[3];
	ImGui::InputFloat3("Eye", eyePosition);

	//camera.getModelviewMatrix();
	//camera.getProjectionMatrix();

	projectionMatrixSlot.show(pos, drawList);
	modelviewMatrixSlot.show(pos, drawList);
	*/

}
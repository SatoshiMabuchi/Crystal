#include "CameraNode.h"
#include <imgui.h>

using namespace Crystal::UI;

namespace {
	static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
	static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
}

CameraNode::CameraNode(const int id, const std::string& name, const ImVec2& pos) :
	INode(id, name, pos)
{}

void CameraNode::show(ImDrawList* drawList, ImVec2 offset)
{
	ImGui::PushID(this->getId());

	drawList->AddRectFilled(getPosition() + offset, getPosition() + offset + ImVec2(100, 100), ImColor(60, 60, 60), 4.0f);

	projectionMatrixSlot.show(offset + getPosition() + ImVec2(100,0), drawList);
	modelviewMatrixSlot.show(offset + getPosition() + ImVec2(100, 10), drawList);
	//drawList->AddCircleFilled(offset + ImVec2(10, 10), 10, ImColor(255, 100, 100, 100));

	ImGui::PopID();
	/*

	ImGui::Button(name.c_str(), ImVec2(100, 100));
	static float eyePosition[3];
	ImGui::InputFloat3("Eye", eyePosition);

	//camera.getModelviewMatrix();
	//camera.getProjectionMatrix();

	projectionMatrixSlot.show(pos, drawList);
	modelviewMatrixSlot.show(pos, drawList);
	*/
}


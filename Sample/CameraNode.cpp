#include "CameraNode.h"
#include <imgui.h>

using namespace Crystal::UI;

namespace {
	static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
	static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
}

CameraNode::CameraNode(const int id, const std::string& name, const ImVec2& pos) :
	id(id),
	name(name),
	pos(pos)
{}


void CameraNode::show()
{
	ImGui::PushID(this->id);

	ImGui::Button(name.c_str(), ImVec2(100, 100));
	static float eyePosition[3];
	ImGui::InputFloat3("Eye", eyePosition);

	/*
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	const ImVec2 NODE_WINDOW_PADDING(8.0f, 8.0f);


	// Display node contents first
	draw_list->ChannelsSetCurrent(1); // Foreground
	ImGui::SetCursorScreenPos(pos + NODE_WINDOW_PADDING);

	ImGui::BeginGroup(); // Lock horizontal position
	ImGui::Text("%s", this->name.c_str());

	ImGui::EndGroup();

	draw_list->ChannelsSetCurrent(0); // Background
	ImGui::SetCursorScreenPos(pos);
	ImGui::InvisibleButton("node", ImVec2(100,100));
	ImU32 node_bg_color = ImColor(60, 60, 60);
	draw_list->AddRectFilled(pos, pos + ImVec2(100, 100), node_bg_color, 4.0f);
	//draw_list->AddRect(node_rect_min, node_rect_max, ImColor(100, 100, 100), 4.0f);

	*/

	ImGui::PopID();

}
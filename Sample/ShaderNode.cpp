#include "ShaderNode.h"
#include "ShaderSlot.h"
#include "GLVSEditor.h"

#include "../Shader/PointRenderer.h"
#include "../Shader/ShaderObject.h"

using namespace Crystal::Shader;
using namespace Crystal::UI;

namespace {

	static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
	static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
}


void ShaderNode::build()
{
	const auto vsSource = vsEditor.getSource();
	const auto fsSource = fsEditor.getSource();
	bool b = shader.build(vsSource, fsSource);
	const std::string str = shader.getLog();
	int len = str.length();
	log = new char[len + 1];
	memcpy(log, str.c_str(), len + 1);

	const auto& uniforms = shader.getActiveUniforms();
	for (const auto u : uniforms) {
		createInputSlot(u->getName(), u->getTypeName());
	}
	const auto& attrs = shader.getActiveAttributes();
	for (const auto a : attrs) {
		createInputSlot(a->getName(), a->getTypeName());
	}
	//shader.getActiveAttributes();
}

ShaderInputSlot* ShaderNode::createInputSlot(const std::string& name,const std::string& type)
{
	auto slot = new ShaderInputSlot(name, type, this, inputSlots.size());
	inputSlots.push_back(slot);
	return slot;
}

ShaderOutputSlot* ShaderNode::createOutputSlot()
{
	auto slot = new ShaderOutputSlot(this, outputSlots.size());
	outputSlots.push_back(slot);
	return slot;
}

void ShaderNode::clear() {
	for (auto s : inputSlots) {
		delete s;
	}
	inputSlots.clear();
	for (auto s : outputSlots) {
		delete s;
	}
	outputSlots.clear();
}

void ShaderNode::show(ImVec2 offset, ShaderNode* selectedNode, ShaderNode* hoveredNode, bool& open_context_menu)
{
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	const ImVec2 NODE_WINDOW_PADDING(8.0f, 8.0f);

	ImGui::PushID(this->id);
	ImVec2 node_rect_min = offset + this->pos;

	// Display node contents first
	draw_list->ChannelsSetCurrent(1); // Foreground
	bool old_any_active = ImGui::IsAnyItemActive();
	ImGui::SetCursorScreenPos(node_rect_min + NODE_WINDOW_PADDING);

	ImGui::BeginGroup(); // Lock horizontal position
	ImGui::Text("%s", this->name.c_str());
	if (ImGui::Button("VertexShader")) {
		ImGui::OpenPopup("VertexShader");
	}
	if (ImGui::BeginPopupModal("VertexShader")) {
		vsEditor.show();
		if (ImGui::Button("Close")) {
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	if (ImGui::Button("FragmentShader")) {
		ImGui::OpenPopup("FragmentShader");
	}
	if (ImGui::BeginPopupModal("FragmentShader")) {
		fsEditor.show();
		if (ImGui::Button("Close")) {
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	if (ImGui::Button("Link")) {
		build();
	}
	ImGui::InputTextMultiline("Log", log, 1024);
	ImGui::EndGroup();

	// Save the size of what we have emitted and whether any of the widgets are being used
	bool node_widgets_active = (!old_any_active && ImGui::IsAnyItemActive());
	this->size = ImGui::GetItemRectSize() + NODE_WINDOW_PADDING + NODE_WINDOW_PADDING;
	ImVec2 node_rect_max = node_rect_min + this->size;

	// Display node box
	draw_list->ChannelsSetCurrent(0); // Background
	ImGui::SetCursorScreenPos(node_rect_min);
	ImGui::InvisibleButton("node", this->size);
	if (ImGui::IsItemHovered()) {
		hoveredNode = this;
		open_context_menu |= ImGui::IsMouseClicked(1);
	}
	bool node_moving_active = ImGui::IsItemActive();
	if (node_widgets_active || node_moving_active) {
		selectedNode = this;
	}
	if (node_moving_active && ImGui::IsMouseDragging(0)) {
		this->pos =  this->pos + ImGui::GetIO().MouseDelta;
	}

	ImU32 node_bg_color = (hoveredNode == this || (hoveredNode == nullptr && selectedNode == this)) ? ImColor(75, 75, 75) : ImColor(60, 60, 60);
	draw_list->AddRectFilled(node_rect_min, node_rect_max, node_bg_color, 4.0f);
	draw_list->AddRect(node_rect_min, node_rect_max, ImColor(100, 100, 100), 4.0f);
	for (auto slot : inputSlots) {
		slot->draw(draw_list, offset);
	}
	for (auto slot : outputSlots) {
		slot->draw(draw_list, offset);
	}

	ImGui::PopID();
}
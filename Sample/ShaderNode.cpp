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

	std::string getBuildinVertexShaderSource()
	{
		std::ostringstream stream;
		stream
			<< "#version 150" << std::endl
			<< "in vec3 position;" << std::endl
			<< "in int id;" << std::endl
			<< "in float pointSize;" << std::endl
			<< "in vec4 color;" << std::endl
			<< "out vec4 vColor;" << std::endl
			<< "uniform mat4 projectionMatrix;" << std::endl
			<< "uniform mat4 modelviewMatrix;" << std::endl
			<< "void main(void) {" << std::endl
			<< "	gl_Position = projectionMatrix * modelviewMatrix * vec4(position, 1.0);" << std::endl
			<< "	gl_PointSize = pointSize / gl_Position.w;" << std::endl
			<< "	vColor = color;" << std::endl
			<< "}" << std::endl;
		return stream.str();
	}

	std::string getBuildinFragmentShaderSource()
	{
		std::ostringstream stream;
		stream
			<< "#version 150" << std::endl
			<< "in vec4 vColor;" << std::endl
			<< "out vec4 fragColor;" << std::endl
			<< "void main(void) {" << std::endl
			<< "	vec2 coord = gl_PointCoord * 2.0 - 1.0;" << std::endl
			<< "	float distSquared = 1.0 - dot(coord, coord);" << std::endl
			<< "	if (distSquared < 0.0) {" << std::endl
			<< "		discard;" << std::endl
			<< "	}" << std::endl
			<< "	fragColor.rgba = vColor;" << std::endl
			<< "	fragColor.a = sqrt(distSquared) * vColor.a;" << std::endl
			<< "	fragColor.a = 0.1;//sqrt(distSquared);" << std::endl
			<< "}" << std::endl;
		return stream.str();
	}
}


void ShaderNode::build()
{
	const auto vsSource = getBuildinVertexShaderSource();
	const auto fsSource = getBuildinFragmentShaderSource();
	bool b = shader.build(vsSource, fsSource);
	const auto& uniforms = shader.getActiveUniforms();
	for (const auto u : uniforms) {
		createInputSlot(u.name, u.getTypeName());
	}
	const auto& attrs = shader.getActiveAttributes();
	for (const auto a : attrs) {
		createInputSlot(a.name, a.getTypeName());
	}
	vsEditor.setSource(vsSource);

	//shader.getActiveAttributes();
}

ShaderInputSlot* ShaderNode::createInputSlot(const std::string& name,const std::string& type)
{
	auto slot = new ShaderInputSlot(name, type, this, inputSlots.size());
	std::cout << name << std::endl;
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

void ShaderNode::show(ImVec2 offset, ShaderNode* selectedNode, ShaderNode* hoveredNodeInList, ShaderNode* hoveredNodeInScene, bool& open_context_menu)
{
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	const float NODE_SLOT_RADIUS = 4.0f;
	const ImVec2 NODE_WINDOW_PADDING(8.0f, 8.0f);

	ImGui::PushID(this->id);
	ImVec2 node_rect_min = offset + this->pos;

	// Display node contents first
	draw_list->ChannelsSetCurrent(1); // Foreground
	bool old_any_active = ImGui::IsAnyItemActive();
	ImGui::SetCursorScreenPos(node_rect_min + NODE_WINDOW_PADDING);
	ImGui::BeginGroup(); // Lock horizontal position
	ImGui::Text("%s", this->name.c_str());
	static bool showShaderSource = false;
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
		hoveredNodeInScene = this;
		open_context_menu |= ImGui::IsMouseClicked(1);
	}
	bool node_moving_active = ImGui::IsItemActive();
	if (node_widgets_active || node_moving_active) {
		selectedNode = this;
	}
	if (node_moving_active && ImGui::IsMouseDragging(0)) {
		this->pos =  this->pos + ImGui::GetIO().MouseDelta;
	}

	ImU32 node_bg_color = (hoveredNodeInList == this || hoveredNodeInScene == this || (hoveredNodeInList == nullptr && selectedNode == this)) ? ImColor(75, 75, 75) : ImColor(60, 60, 60);
	draw_list->AddRectFilled(node_rect_min, node_rect_max, node_bg_color, 4.0f);
	draw_list->AddRect(node_rect_min, node_rect_max, ImColor(100, 100, 100), 4.0f);
	for (auto slot : inputSlots) {
		draw_list->AddCircleFilled(offset + slot->getPosition(), NODE_SLOT_RADIUS, ImColor(150, 150, 150, 150));
	}
	for (auto slot : outputSlots) {
		draw_list->AddCircleFilled(offset + slot->getPosition(), NODE_SLOT_RADIUS, ImColor(150, 150, 150, 150));
	}

	ImGui::PopID();
}
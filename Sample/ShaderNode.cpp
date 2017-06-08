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

void ShaderNode::show(ImVec2 offset)
{
	ImDrawList* drawList = ImGui::GetWindowDrawList();
	const ImVec2 NODE_WINDOW_PADDING(8.0f, 8.0f);

	ImGui::PushID(this->id);
	const auto rectMin = offset + this->pos;

	drawList->ChannelsSetCurrent(1);
	ImGui::SetCursorScreenPos(rectMin + NODE_WINDOW_PADDING);

	ImGui::BeginGroup();
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


	ImGui::PopID();
}

void ShaderNode::showBackGround(ImVec2 offset)
{
	ImDrawList* drawList = ImGui::GetWindowDrawList();

	ImGui::PushID(this->id);
	const auto rectMin = offset + this->pos;

	const ImVec2 NODE_WINDOW_PADDING(8.0f, 8.0f);

	this->size = ImGui::GetItemRectSize() + NODE_WINDOW_PADDING + NODE_WINDOW_PADDING;
	const auto rectMax = rectMin + this->size;

	drawList->ChannelsSetCurrent(0);
	ImGui::SetCursorScreenPos(rectMin);
	ImGui::InvisibleButton("node", this->size);
	const bool isActive_ = isActive();
	if (isActive_ && ImGui::IsMouseDragging(0)) {
		this->pos = this->pos + ImGui::GetIO().MouseDelta;
	}

	drawList->AddRectFilled(rectMin, rectMax, ImColor(60, 60, 60), 4.0f);
	drawList->AddRect(rectMin, rectMax, ImColor(100, 100, 100), 4.0f);
	for (auto slot : inputSlots) {
		slot->draw(drawList, offset);
	}
	for (auto slot : outputSlots) {
		slot->draw(drawList, offset);
	}
	ImGui::PopID();
}

bool ShaderNode::isActive()
{
	ImGui::PushID(this->id);
	const bool result = ImGui::IsItemActive();
	ImGui::PopID();
	return result;
}

bool ShaderNode::isHovered()
{
	ImGui::PushID(this->id);
	const bool result = ImGui::IsItemHovered();
	ImGui::PopID();
	return result;
}
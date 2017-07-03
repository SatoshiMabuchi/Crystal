#include "ParticleNode.h"
#include "ImGuiExt.h"

using namespace Crystal::UI;


ParticleNode::ParticleNode(const int id, const std::string& name, const ImVec2& pos) :
	INode(id, name, pos)
{}

void ParticleNode::show(ImDrawList* drawList, ImVec2 offset)
{
	ImGui::PushID(this->getId());

	drawList->AddRectFilled(getPosition() + offset, getPosition() + offset + ImVec2(100, 100), ImColor(60, 60, 60), 4.0f);

	//projectionMatrixSlot.show(offset + getPosition() + ImVec2(100, 0), drawList);
	//modelviewMatrixSlot.show(offset + getPosition() + ImVec2(100, 10), drawList);
	//drawList->AddCircleFilled(offset + ImVec2(10, 10), 10, ImColor(255, 100, 100, 100));

	ImGui::PopID();
}
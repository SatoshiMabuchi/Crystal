#include "Model.h"
#include <fstream>
#include <cereal/archives/json.hpp>
#include "CameraNode.h"
#include "ShaderNode.h"

using namespace Crystal::UI;

bool Model::save(const std::string& filename) const
{
	std::ofstream stream(filename);
	if(!stream.is_open()) {
		return false;
	}
	cereal::JSONOutputArchive archive(stream);
	archive(*cameraNode);
	return true;
}

bool Model::load(const std::string& filename)
{
	std::ifstream stream(filename);
	if (!stream.is_open()) {
		return false;
	}
	cereal::JSONInputArchive archive(stream);
	archive(*cameraNode);
	return true;
}

void Model::build()
{
	auto smoothingNode = new ShaderNode(0, "Smoothing", ImVec2(40, 50));
	auto depthNode = new ShaderNode(1, "Depth", ImVec2(40, 150));
	auto thicknessNode = new ShaderNode(2, "Thickness", ImVec2(270, 80));
	cameraNode = new CameraNode(3, "Camera", ImVec2(10, 10));
	nodes.push_back(smoothingNode);
	nodes.push_back(depthNode);
	nodes.push_back(thicknessNode);
	auto slot1 = smoothingNode->createOutputSlot();
	auto slot2 = depthNode->createInputSlot("", "");
	auto slot3 = thicknessNode->createInputSlot("", "");
	//links.push_back(ShaderLink(slot1, slot2));
	//links.push_back(ShaderLink(slot1, slot3));
}

void Model::draw(ImDrawList* draw_list, ImVec2 offset)
{
	cameraNode->show(draw_list, offset);

	for (auto node : nodes) {
		node->show(draw_list, offset);
	}
	for (auto node : nodes) {
		node->showBackGround(offset);
	}
	/*
	for (auto node : nodes) {
		if (node->isActive()) {
			selectedNode = node;
		}
	}
	for (auto node : nodes) {
		if (node->isHovered()) {
			hoveredNodeInScene = node;
			open_context_menu |= ImGui::IsMouseClicked(1);
		}
	}
	*/
	draw_list->ChannelsMerge();

}
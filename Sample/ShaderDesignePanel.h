#ifndef __CRYSTAL_UI_SHADER_DESIGNE_PANEL_H__
#define __CRYSTAL_UI_SHADER_DESIGNE_PANEL_H__

#include "imgui.h"
#include <string>
#include <vector>

namespace Crystal {
	namespace UI {

struct Node
{
	Node(int id, std::string name, const ImVec2& pos, float value, const ImVec4& color, int inputs_count, int outputs_count) :
		id(id),
		name(name),
		pos(pos),
		value(value)
	{ Color = color; InputsCount = inputs_count; OutputsCount = outputs_count; }

	int id;
	std::string name;
	ImVec2 pos;
	ImVec2 size;
	float value;
	ImVec4  Color;
	int InputsCount;
	int OutputsCount;

	ImVec2 GetInputSlotPos(int slot_no) const { return ImVec2(pos.x, pos.y + size.y * ((float)slot_no + 1) / ((float)InputsCount + 1)); }
	ImVec2 GetOutputSlotPos(int slot_no) const { return ImVec2(pos.x + size.x, pos.y + size.y * ((float)slot_no + 1) / ((float)OutputsCount + 1)); }
};

struct NodeLink
{
	NodeLink(Node* inputNode, int input_slot, Node* outputNode, int output_slot) :
		inputNode(inputNode),
		outputNode(outputNode)
	{
		InputSlot = input_slot; OutputSlot = output_slot;
	}

	Node* inputNode;
	int InputSlot;
	Node* outputNode;
	int OutputSlot;
};

class ShaderDesignePanel
{
public:
	void show();

private:
	std::vector<Node*> nodes;
	std::vector<NodeLink> links;
	bool inited = false;
	ImVec2 scrolling = ImVec2(0.0f, 0.0f);
	bool show_grid = true;
	int node_selected = -1;
};
	}
}

#endif

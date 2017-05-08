#ifndef __CRYSTAL_UI_SHADER_DESIGNE_PANEL_H__
#define __CRYSTAL_UI_SHADER_DESIGNE_PANEL_H__

#include "imgui.h"
#include <string>
#include <vector>

namespace Crystal {
	namespace UI {

struct Node
{
	Node(int id, std::string name, const ImVec2& pos, float value, const ImVec4& color, int inputs_count, int outputs_count)
	{ ID = id; this->name = name; Pos = pos; Value = value; Color = color; InputsCount = inputs_count; OutputsCount = outputs_count; }

	int ID;
	std::string name;
	ImVec2  Pos, Size;
	float   Value;
	ImVec4  Color;
	int     InputsCount, OutputsCount;

	ImVec2 GetInputSlotPos(int slot_no) const { return ImVec2(Pos.x, Pos.y + Size.y * ((float)slot_no + 1) / ((float)InputsCount + 1)); }
	ImVec2 GetOutputSlotPos(int slot_no) const { return ImVec2(Pos.x + Size.x, Pos.y + Size.y * ((float)slot_no + 1) / ((float)OutputsCount + 1)); }
};

struct NodeLink
{
	NodeLink(int input_idx, int input_slot, int output_idx, int output_slot) { InputIdx = input_idx; InputSlot = input_slot; OutputIdx = output_idx; OutputSlot = output_slot; }

	int     InputIdx, InputSlot, OutputIdx, OutputSlot;

};

class ShaderDesignePanel
{
public:
	void show();

private:
	std::vector<Node> nodes;
	ImVector<NodeLink> links;
	bool inited = false;
	ImVec2 scrolling = ImVec2(0.0f, 0.0f);
	bool show_grid = true;
	int node_selected = -1;
};
	}
}

#endif

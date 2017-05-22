#ifndef __CRYSTAL_UI_SHADER_NODE_H__
#define __CRYSTAL_UI_SHADER_NODE_H__

#include <string>
#include "imgui.h"
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>

#include "../Shader/ShaderObject.h"

namespace Crystal {
	namespace UI {
		class ShaderInputSlot;
		class ShaderOutputSlot;

class ShaderNode
{
public:
	ShaderNode(int id, std::string name, const ImVec2& pos, float value, const ImVec4& color, int inputs_count, int outputs_count) :
		id(id),
		name(name),
		pos(pos),
		value(value)
	{
		Color = color;
	}

	void build();

	void setName(const std::string& name) { this->name = name; }

	ShaderInputSlot* createInputSlot();

	ShaderOutputSlot* createOutputSlot();

	int id;
	std::string name;
	ImVec2 pos;
	ImVec2 size;
	float value;
	ImVec4  Color;
	std::vector<ShaderInputSlot*> inputSlots;
	std::vector<ShaderOutputSlot*> outputSlots;
	Shader::ShaderObject shader;

	ImVec2 GetInputSlotPos(int slot_no) const { return ImVec2(pos.x, pos.y + size.y * ((float)slot_no + 1) / ((float)inputSlots.size() + 1)); }
	ImVec2 GetOutputSlotPos(int slot_no) const { return ImVec2(pos.x + size.x, pos.y + size.y * ((float)slot_no + 1) / ((float)outputSlots.size() + 1)); }

	template<class Archive>
	void serialize(Archive & archive)
	{
		archive(name, id);
	}
};

	}
}

#endif
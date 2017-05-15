#ifndef __CRYSTAL_UI_SHADER_NODE_H__
#define __CRYSTAL_UI_SHADER_NODE_H__

#include <string>
#include "imgui.h"
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>

#include "../Shader/ShaderObject.h"

namespace Crystal {
	namespace UI {

class ShaderNode
{
public:
	ShaderNode(int id, std::string name, const ImVec2& pos, float value, const ImVec4& color, int inputs_count, int outputs_count) :
		id(id),
		name(name),
		pos(pos),
		value(value)
	{
		Color = color; InputsCount = inputs_count; OutputsCount = outputs_count;
	}

	void build();


	void setName(const std::string& name) { this->name = name; }

	int id;
	std::string name;
	ImVec2 pos;
	ImVec2 size;
	float value;
	ImVec4  Color;
	int InputsCount;
	int OutputsCount;
	Shader::ShaderObject shader;

	ImVec2 GetInputSlotPos(int slot_no) const { return ImVec2(pos.x, pos.y + size.y * ((float)slot_no + 1) / ((float)InputsCount + 1)); }
	ImVec2 GetOutputSlotPos(int slot_no) const { return ImVec2(pos.x + size.x, pos.y + size.y * ((float)slot_no + 1) / ((float)OutputsCount + 1)); }

	template<class Archive>
	void serialize(Archive & archive)
	{
		archive(name, id);
	}
};

	}
}

#endif
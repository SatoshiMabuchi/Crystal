#ifndef __CRYSTAL_UI_SHADER_NODE_H__
#define __CRYSTAL_UI_SHADER_NODE_H__

#include <string>
#include "imgui.h"
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
#include "../Util/UnCopyable.h"

#include "../Shader/ShaderObject.h"
#include "GLVSEditor.h"
#include "GLFSEditor.h"

namespace Crystal {
	namespace UI {
		class ShaderInputSlot;
		class ShaderOutputSlot;

class ShaderNode : private UnCopyable
{
public:
	ShaderNode(int id, std::string name, const ImVec2& pos) :
		id(id),
		name(name),
		pos(pos)
	{
	}

	~ShaderNode() {
		clear();
	}

	void build();

	void setName(const std::string& name) { this->name = name; }

	ShaderInputSlot* createInputSlot(const std::string& name, const std::string& type);

	ShaderOutputSlot* createOutputSlot();

	void clear();

	void show(ImVec2 offset, ShaderNode* selectedNode, ShaderNode* hoveredNodeInList, ShaderNode* hoveredNodeInScene, bool& open_context_menu);

	int id;
	std::string name;
	ImVec2 pos;
	ImVec2 size;
	std::vector<ShaderInputSlot*> inputSlots;
	std::vector<ShaderOutputSlot*> outputSlots;
	Shader::ShaderObject shader;
	Crystal::UI::GLVSEditor vsEditor;
	Crystal::UI::GLFSEditor fsEditor;

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
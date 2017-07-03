#pragma once

#include <string>
#include "imgui.h"
#include "../Util/UnCopyable.h"

#include "../Shader/ShaderObject.h"
#include "GLVSEditor.h"
#include "GLFSEditor.h"
#include "INode.h"

namespace Crystal {
	namespace UI {
		class ShaderInputSlot;
		class ShaderOutputSlot;

class ShaderNode : public INode
{
public:
	ShaderNode(int id, std::string name, const ImVec2& pos) :
		INode(id, name, pos),
		log("")
	{
	}

	~ShaderNode() {
		clear();
	}

	void build();

	ShaderInputSlot* createInputSlot(const std::string& name, const std::string& type);

	ShaderOutputSlot* createOutputSlot();

	void clear();

	void show(ImDrawList* drawList, ImVec2 offset) override;

	void showBackGround(ImVec2 offset);

	bool isActive();

	bool isHovered();

	std::vector<ShaderInputSlot*> inputSlots;
	std::vector<ShaderOutputSlot*> outputSlots;
	Shader::ShaderObject shader;
	char* log;
	Crystal::UI::GLVSEditor vsEditor;
	Crystal::UI::GLFSEditor fsEditor;

	template<class Archive>
	friend void serialize(Archive& archive, ShaderNode& shaderNode);
};

	}
}


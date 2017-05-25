#pragma once

#include <imgui.h>
#include <string>

namespace Crystal {
	namespace UI {
		class ShaderNode;

class ShaderInputSlot
{
public:
	explicit ShaderInputSlot(const std::string& name, const std::string& type, ShaderNode* parent, const int id) :
		name(name),
		type(type),
		parent(parent),
		id(id)
	{}

	ImVec2 getPosition() const;

private:
	std::string name;
	std::string type;
	ShaderNode* parent;
	const int id;
};

class ShaderOutputSlot
{
public:
	explicit ShaderOutputSlot(ShaderNode* parent, const int id) :
		parent(parent),
		id(id)
	{}

	ImVec2 getPosition() const;

private:
	ShaderNode* parent;
	const int id;
};

	}
}
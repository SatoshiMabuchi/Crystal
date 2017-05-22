#pragma once

#include <imgui.h>

namespace Crystal {
	namespace UI {
		class ShaderNode;

class ShaderInputSlot
{
public:
	explicit ShaderInputSlot(ShaderNode* parent, const int id) :
		parent(parent),
		id(id)
	{}

	ImVec2 getPosition() const;

private:
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
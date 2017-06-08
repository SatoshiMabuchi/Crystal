#pragma once

#include <imgui.h>
#include <string>
#include "INode.h"

namespace Crystal {
	namespace UI {

class ShaderInputSlot : public IInSlot
{
public:
	ShaderInputSlot(const std::string& name, const std::string& type, INode* parent, const int id) :
		IInSlot(parent),
		type(type),
		id(id)
	{}

private:
	std::string name;
	std::string type;
	const int id;
};

class ShaderOutputSlot : public IOutSlot
{
public:
	explicit ShaderOutputSlot(INode* parent, const int id) :
		IOutSlot(parent),
		id(id)
	{}

private:
	const int id;
};

	}
}
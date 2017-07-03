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

	template<class Archive>
	friend void serialize(Archive& archive, ShaderInputSlot& input);

private:
	std::string name;
	std::string type;
	int id;
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
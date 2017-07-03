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

	friend std::ostream& operator<<(std::ostream&, const ShaderInputSlot&);

private:
	std::string name;
	std::string type;
	const int id;
};

std::ostream& operator<<(std::ostream& stream, const ShaderInputSlot& slot);

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
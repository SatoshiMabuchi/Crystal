#pragma once

#include <vector>
#include <string>
#include "imgui.h"

namespace Crystal {
	namespace UI {

class IInSlot
{
public:
	virtual ~IInSlot() {}

	virtual void show(const ImVec2& pos, ImDrawList* drawList);
};

class IOutSlot
{
public:
	virtual ~IOutSlot() {}

	virtual void show(const ImVec2& pos, ImDrawList* drawList);
};

class INode
{
public:
	INode(const int id, const std::string& name, const ImVec2& pos) :
		id(id),
		name(name),
		position(pos)
	{}

	virtual ~INode() {}

	const int getId() const { return id; }

	const std::string getName() const { return name; }

	const ImVec2 getPosition() const { return position; }

private:
	const int id;
	const std::string name;
	const ImVec2 position;

	std::vector<IInSlot*> inputs;
	std::vector<IOutSlot*> outputs;
};

	}
}
#pragma once

namespace Crystal {
	namespace UI {

class IObject
{
public:
	explicit IObject(const int id) :
		id(id)
	{}

	~IObject() {};

	int getId() const { return id; }
private:
	int id;
};
	}
}
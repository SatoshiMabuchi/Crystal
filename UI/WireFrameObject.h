#pragma once

#include "IObject.h"
#include "../Shape/WireFrame.h"
#include "../Graphics/ColorRGBA.h"

namespace Crystal {
	namespace UI {

class WireFrameObject : public IObject
{
public:
	WireFrameObject(const int id, Shape::WireFrame* shape) :
		IObject(id),
		shape(shape)
	{}

	~WireFrameObject() {};

	Shape::WireFrame* getShape() const { return shape; }

private:
	Shape::WireFrame* shape;
};

	}
}
#pragma once

#include "IObject.h"
#include "../Shape/PolygonMesh.h"
#include "../Graphics/ColorRGBA.h"

namespace Crystal {
	namespace UI {

class PolygonMeshObject : public IObject
{
public:
	PolygonMeshObject(const int id, Shape::PolygonMesh* shape) :
		IObject(id),
		shape(shape)
	{}

	~PolygonMeshObject() {};

	Shape::PolygonMesh* getShape() const { return shape; }

private:
	Shape::PolygonMesh* shape;
};

	}
}
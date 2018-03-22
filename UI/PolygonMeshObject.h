#pragma once

#include "IObject.h"
#include "../Shape/PolygonMesh.h"
#include "../Graphics/ColorRGBA.h"

namespace Crystal {
	namespace UI {

class PolygonMeshObject : public IObject
{
public:
	PolygonMeshObject(const int id, Shape::PolygonMesh* shape, const Graphics::ColorRGBAf& color) :
		IObject(id),
		shape(shape),
		color(color)
	{}

	~PolygonMeshObject() {};

	Shape::PolygonMesh* getShape() const { return shape; }

	Graphics::ColorRGBAf getColor() const { return color; }

private:
	Shape::PolygonMesh* shape;
	Graphics::ColorRGBAf color;
};

	}
}
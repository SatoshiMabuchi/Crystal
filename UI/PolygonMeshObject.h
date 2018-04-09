#pragma once

#include "IObject.h"
#include "../Shape/PolygonMesh.h"
#include "../Graphics/ColorRGBA.h"
#include "../Graphics/Material.h"

namespace Crystal {
	namespace UI {

class PolygonMeshObject : public IObject
{
public:
	PolygonMeshObject(const int id, Shape::PolygonMesh* shape, const Graphics::Material& material) :
		IObject(id),
		shape(shape),
		material(material)
	{}

	~PolygonMeshObject() {};

	Shape::PolygonMesh* getShape() const { return shape; }

	Graphics::Material getMaterial() const { return material; }

private:
	Shape::PolygonMesh* shape;
	Graphics::Material material;
};

	}
}
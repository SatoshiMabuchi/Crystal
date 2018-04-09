#pragma once

#include "../Math/Line3d.h"
#include "../Math/Sphere3d.h"
#include "../Math/Box3d.h"
#include "PolygonMesh.h"

namespace Crystal {
	namespace Shape {

class PolygonMeshBuilder
{
public:
	PolygonMeshBuilder() :
		nextId(0)
	{}

	void build(const Math::Box3d& box);

	void build(const Math::Sphere3d& sphere, const int udiv, const int vdiv);

	PolygonMesh* getPolygonMesh() const { return new PolygonMesh(faces); }

private:
	//void buildEdges();

	std::list<Face*> faces;
	//std::vector<Vertex*> vertices;
	int nextId;
};

	}
}
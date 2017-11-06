#include "stdafx.h"
#include "Vertex.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;

Vertex::Vertex(const Vector3d<float>& position, const unsigned int id) :
	position(position),
	id(id)
{}

Vertex::Vertex(const Vector3d<float>& position, const Vector3d<float>& normal, const unsigned int id) :
	position(position),
	normal(normal),
	id(id)
{}

/*
Vertex::Vertex(const Vector3d<float>& position, const Vector3d<float>& normal, const Vector2df& texCoord, const unsigned int id) :
	Point3d<float>(position, normal, texCoord),
	id(id)
{}
*/

Vertex* Vertex::clone()
{
	return new Vertex(getPosition(), getNormal(), id);
}

void Vertex::reverse()
{
	this->normal = (-getNormal());
}

Box3d<float> Util::getBoundingBox(const std::list<Vertex*>& vertices)
{
	Box3d<float> box(vertices.front()->getPosition());
	for (auto v : vertices) {
		box.add(v->getPosition());
	}
	return box;
}
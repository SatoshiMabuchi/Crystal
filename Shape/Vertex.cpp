#include "stdafx.h"
#include "Vertex.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;

Vertex::Vertex(const Vector3df& position, const unsigned int id) :
	position(position),
	id(id)
{}

Vertex::Vertex(const Vector3df& position, const Vector3df& normal, const unsigned int id) :
	position(position),
	normal(normal),
	id(id)
{}

Vertex::Vertex(const Vector3df& position, const Vector3df& normal, const Vector2df& texCoord, const unsigned int id) :
	position(position),
	normal(normal),
	texCoord(texCoord),
	id(id)
{}

Vertex* Vertex::clone()
{
	return new Vertex(getPosition(), getNormal(), id);
}

void Vertex::reverse()
{
	this->normal = (-getNormal());
}

Box3d Util::getBoundingBox(const std::list<Vertex*>& vertices)
{
	Box3d box(vertices.front()->getPosition());
	for (auto v : vertices) {
		box.add(v->getPosition());
	}
	return box;
}
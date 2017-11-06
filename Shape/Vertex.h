#ifndef __CRYSTAL_SHAPE_VERTEX_H__
#define __CRYSTAL_SHAPE_VERTEX_H__

#include "../Math/Vector2d.h"
#include "../Math/Vector3d.h"
#include "../Math/Matrix4d.h"
#include "../Math/Box3d.h"
#include "../Util/UnCopyable.h"
#include <list>
#include <array>

namespace Crystal {
	namespace Shape {

class Vertex
{
public:
	Vertex(const Math::Vector3df& position, const unsigned int id = -1);

	Vertex(const Math::Vector3df& position, const Math::Vector3df& normal, const unsigned int id = -1);

	Vertex(const Math::Vector3df& position, const Math::Vector3df& normal, const Math::Vector2df& texCoord, const unsigned int id = -1);

	Vertex* clone();

	void setId(const int id) { this->id = id; }

	unsigned int getId() const { return id; }

	void reverse();

	Math::Vector3df getPosition() const { return position; }

	Math::Vector3df getNormal() const { return normal; }

	void move(const Math::Vector3df& v) { this->position += v; }

	void setNormal(const Math::Vector3df& n) { this->normal = n; }

	//void scale(const Vector3df& s) { this->position.scale(s); }

private:
	Math::Vector3df position;
	Math::Vector3df normal;
	Math::Vector2df texCoord;
	unsigned int id;
};


class Util {
public:
	static Math::Box3d getBoundingBox(const std::list<Vertex*>& vertices);
};

	}
}
#endif
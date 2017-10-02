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
	Vertex(const Math::Vector3d<float>& position, const unsigned int id = -1);

	Vertex(const Math::Vector3d<float>& position, const Math::Vector3d<float>& normal, const unsigned int id = -1);

	Vertex(const Math::Vector3d<float>& position, const Math::Vector3d<float>& normal, const Math::Vector2d<float>& texCoord, const unsigned int id = -1);

	Vertex* clone();

	void setId(const int id) { this->id = id; }

	unsigned int getId() const { return id; }

	void reverse();

	Math::Vector3d<float> getPosition() const { return position; }

	Math::Vector3d<float> getNormal() const { return normal; }

	void move(const Math::Vector3d<float>& v) { this->position += v; }

	void setNormal(const Math::Vector3d<float>& n) { this->normal = n; }

	//void scale(const Vector3d<float>& s) { this->position.scale(s); }

private:
	Math::Vector3d<float> position;
	Math::Vector3d<float> normal;
	Math::Vector2d<float> texCoord;
	unsigned int id;
};


class Util {
public:
	static Math::Box3d<float> getBoundingBox(const std::list<Vertex*>& vertices);
};

	}
}
#endif
#ifndef __CRYSTAL_MATH_SPHERE_H__
#define __CRYSTAL_MATH_SPHERE_H__

#include "Vector3d.h"

#include <vector>
#include <cassert>
#include <algorithm>

namespace Crystal {
	namespace Math {
		class Box3d;

class Sphere3d
{
public:
	Sphere3d();

	Sphere3d(const Vector3dd& center, const float radius);

	Sphere3d(const Math::Box3d& boundingBox);

	Vector3dd getPositionByAngle(const double u, const double v) const;

	Vector3dd getPositionByParam(const double u, const double v) const;

	//Vector3dd getNormalByAngle(const T u, const T v) const;

	//Vector3dd getNormalByParam(const T u, const T v) const;

	//Point3d<T> getPoint(const Param<T> u, const Param<T> v) const;

	Vector3dd getCenter() const { return center; }

	double getRadius() const { return radius; }

	bool isValid() const {
		return radius >= 0.0f;
	}

	void outerOffset(const float offsetLength) {
		this->radius += offsetLength;
		assert(isValid());
	}

	Sphere3d getOuterOffset(const float offsetLength) const {
		Sphere3d sphere = *this;
		sphere.radius += offsetLength;
		assert(sphere.isValid());
		return sphere;
	}

	void innerOffset(const float offsetLength) {
		this->radius -= offsetLength;
		assert(isValid());
	}

	Sphere3d getInnerOffset(const float offsetLength) const;

	bool equals(const Sphere3d& rhs) const;

	bool operator==(const Sphere3d& rhs) const;

	bool operator!=(const Sphere3d& rhs) const;

	bool isInner(const Vector3dd& v) const;

	bool isOuter(const Vector3dd& v) const;

private:
	Vector3dd center;
	double radius;
};

	}
}

#endif
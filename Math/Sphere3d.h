#ifndef __CRYSTAL_MATH_SPHERE_H__
#define __CRYSTAL_MATH_SPHERE_H__

#include "Vector3d.h"

#include <vector>
#include <cassert>
#include <algorithm>

namespace Crystal {
	namespace Math {
		template<typename>
		class Box3d;

template<typename T>
class Sphere3d
{
public:
	Sphere3d();

	Sphere3d(const Vector3d<T>& center, const float radius);

	Sphere3d(const Math::Box3d<T>& boundingBox);

	static Sphere3d UnitSphere();

	Math::Box3d<T> getBoundingBox() const;

	std::vector<Vector3d<T>> toPoints(const T divideLength) const;

	Vector3d<T> getPositionByAngle(const T u, const T v) const;

	Vector3d<T> getPositionByParam(const T u, const T v) const;

	//Vector3d<T> getNormalByAngle(const T u, const T v) const;

	//Vector3d<T> getNormalByParam(const T u, const T v) const;

	//Point3d<T> getPoint(const Param<T> u, const Param<T> v) const;

	Vector3d<T> getCenter() const { return center; }

	T getRadius() const { return radius; }

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

	bool isInner(const Vector3d<T>& v) const;

	bool isOuter(const Vector3d<T>& v) const;

	bool isOnStrictly(const Vector3d<T>& v) const;

	bool isOnLoosely(const Vector3d<T>& v) const;

private:
	Vector3d<T> center;
	T radius;
};

	}
}

#endif
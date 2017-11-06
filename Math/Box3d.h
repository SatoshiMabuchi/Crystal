#ifndef __CRYSTAL_MATH_BOX_3D_H__
#define __CRYSTAL_MATH_BOX_3D_H__

#include "Vector3d.h"

namespace Crystal {
	namespace Math {
		template<typename>
		class Space3d;
		template<typename>
		class Quad3d;
		template<typename>
		class Line3d;

class Box3d
{
public:
	Box3d();

	Box3d(const Vector3dd& point);

	Box3d(const Vector3dd& pointX, const Vector3dd& pointY);

	~Box3d() = default;

	static Box3d Unit() {
		return Box3d();
	}

	Box3d getBoundingBox() const { return *this; }

	void add(const Vector3dd& v);

	void add(const Box3d& b);

	double getVolume() const;

	Vector3dd getMax() const { return end; }

	Vector3dd getMin() const { return Vector3dd(getMinX(), getMinY(), getMinZ()); }

	Vector3dd getStart() const { return getMin(); }

	Vector3dd getEnd() const { return getMax(); }

	Vector3dd getCenter() const;

	bool isInterior(const Vector3dd& point) const;

	bool isExterior(const Vector3dd& point) const;

	double getMaxX() const { return end.x; }

	double getMinX() const { return start.x; }

	double getMaxY() const { return end.y; }

	double getMinY() const { return start.y; }

	double getMaxZ() const { return end.z; }

	double getMinZ() const { return start.z; }

	Vector3dd getLength() const;

	bool isValid() const;

	bool isShirinked() const;

	bool equals(const Box3d& rhs) const;

	bool operator==(const Box3d& rhs) const { return equals(rhs); }

	bool operator!=(const Box3d& rhs) const { return !equals(rhs); }

	bool hasIntersection(const Box3d& rhs) const;

	Box3d getOverlapped(const Box3d& rhs) const;

	Vector3dd getPosition(const Vector3dd& param) const;

private:
	Vector3dd start;
	Vector3dd end;
};

	}
}

#endif
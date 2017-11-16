#ifndef __CRYSTAL_MATH_BOX_2D_H__
#define __CRYSTAL_MATH_BOX_2D_H__

#include "Vector2d.h"
#include <array>

namespace Crystal {
	namespace Math {

class Box2d
{
public:
	Box2d() :
		Box2d(Vector2df(0, 0), Vector2df(1, 1))
	{}

	Box2d(const Vector2df& pointX, const Vector2df& pointY) {
		const auto x = std::min<float>(pointX.x, pointY.x);
		const auto y = std::min<float>(pointX.y, pointY.y);
		this->start = Vector2df(x, y);
		const auto endX = std::max<float>(pointX.x, pointY.x);
		const auto endY = std::max<float>(pointX.y, pointY.y);
		this->end = Vector2df(endX, endY);
		assert(isValid());
	}


	void add(const Vector2df& v) {
		const auto x = std::min<float>(getMinX(), v.x);
		const auto y = std::min<float>(getMinY(), v.y);
		start = Vector2df(x, y);

		const auto endX = std::max<float>(end.x, v.x);
		const auto endY = std::max<float>(end.y, v.y);
		end = Vector2df(endX, endY);
	}

	void add(const Box2d& b) {
		const auto sx = std::min<float>(getMinX(), b.getMinX());
		const auto sy = std::min<float>(getMinY(), b.getMinY());
		this->start = Vector2df(sx, sy);

		const auto ex = std::max<float>(end.x, b.getMaxX());
		const auto ey = std::max<float>(end.y, b.getMaxY());
		this->end = Vector2df(ex, ey);
	}

	float getArea() const { return (end.x - getMinX()) * (end.y - getMinY());  }

	Vector2df getMax() const { return Vector2df(end[0], end[1]); }

	Vector2df getMin() const { return Vector2df(getMinX(), getMinY()); }

	Vector2df getStart() const { return getMin(); }

	Vector2df getEnd() const { return getMax(); }

	Vector2df getCenter() const {
		return Vector2df(
			(getMinX() + end.x) / 2.0f,
			(getMinY() + end.y) / 2.0f
		);
	}

	//std::vector< Vector2d<T> > toInnerPoints(const T divideLength) const;

	float getMaxX() const { return end[0]; }

	float getMinX() const { return start[0]; }

	float getMaxY() const { return end[1]; }

	float getMinY() const { return start[1]; }

	Vector2df getLength() const { return Vector2df(end.x - getMinX(), end.y - getMinY()); }

	bool isValid() const { return (getMinX() <= end.x) && (getMinY() <= end.y); }

	bool isShirinked() const { return (getMinX() == end.x) && (getMinY() == end.y); }

	bool equals(const Box2d& rhs) const {
		return
			start == rhs.getStart() &&
			end == rhs.getEnd();
	}

	bool operator==(const Box2d& rhs) const { return equals(rhs); }

	bool operator!=(const Box2d& rhs) const { return !equals(rhs); }

	bool hasIntersection(const Box2d& rhs) const {
		const auto distx = std::fabs(getCenter().x - rhs.getCenter().x);
		const auto lx = getLength().x / 2.0f + rhs.getLength().x / 2.0f;

		const auto disty = std::fabs(getCenter().y - rhs.getCenter().y);
		const auto ly = getLength().y / 2.0f + rhs.getLength().y / 2.0f;

		return (distx < lx && disty < ly);
	}

	Box2d getOverlapped(const Box2d& rhs) const {
		assert(hasIntersection(rhs));
		const auto minx = std::max(this->getStart().x, rhs.getStart().x);
		const auto miny = std::max(this->getStart().y, rhs.getStart().y);

		const auto maxx = std::min(this->getEnd().x, rhs.getEnd().x);
		const auto maxy = std::min(this->getEnd().y, rhs.getEnd().y);

		const Vector2df min_(minx, miny);
		const Vector2df max_(maxx, maxy);
		return Box2d(min_, max_);
	}

	std::array< float, 8 > toArray() const
	{
		return{
			getMinX(), getMaxY(),
			getMinX(), getMinY(),
			getMaxX(), getMinY(),
			getMaxX(), getMaxY()
		};
	}

private:
	Vector2df start;
	Vector2df end;
};

	}
}

#endif
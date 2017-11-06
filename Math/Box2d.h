#ifndef __CRYSTAL_MATH_BOX_2D_H__
#define __CRYSTAL_MATH_BOX_2D_H__

#include "Vector2d.h"
#include <array>

namespace Crystal {
	namespace Math {

		class Box2d
		{
		public:
			Box2d();

			Box2d(const Vector2df& pointX, const Vector2df& pointY);

			void add(const Vector2df& v);

			void add(const Box2d& b);

			float getArea() const;

			Vector2df getMax() const { return Vector2df(end[0], end[1]); }

			Vector2df getMin() const { return Vector2df(getMinX(), getMinY()); }

			Vector2df getStart() const { return getMin(); }

			Vector2df getEnd() const { return getMax(); }

			Vector2df getCenter() const;

			//std::vector< Vector2d<T> > toInnerPoints(const T divideLength) const;

			float getMaxX() const { return end[0]; }

			float getMinX() const { return start[0]; }

			float getMaxY() const { return end[1]; }

			float getMinY() const { return start[1]; }

			Vector2df getLength() const {
				return Vector2df(end.x - getMinX(), end.y - getMinY());
			}

			bool isValid() const;

			bool isShirinked() const;

			bool equals(const Box2d& rhs) const;

			bool operator==(const Box2d& rhs) const { return equals(rhs); }

			bool operator!=(const Box2d& rhs) const { return !equals(rhs); }

			bool hasIntersection(const Box2d& rhs) const;

			Box2d getOverlapped(const Box2d& rhs) const;

			//Space3d<T> toSpace() const;

			std::array< float, 8 > toArray() const;

		private:
			Vector2df start;
			Vector2df end;
		};

	}
}

#endif
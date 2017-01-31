#ifndef __CRYSTAL_MATH_TOLERANCE_H__
#define __CRYSTAL_MATH_TOLERANCE_H__

#include <cmath>

namespace Crystal {
	namespace Math {

template<typename T>
class Tolerance
{

};

template<>
class Tolerance < float >
{
public:
	static float getLooseTolerance() {
		return 1.0e-6f;
	}

	static float getStrictTolerance() {
		return 1.0e-12f;
	}

	static bool isEqual(const float x, const float y, const float tolerance) { return ::fabs(x - y) < tolerance; }

	static bool isZeroLoosely(const float x) { return ::fabs(x) < getLooseTolerance(); }

	static bool isEqualLoosely(const float x, const float y) { return ::fabs(x - y) < getLooseTolerance(); }

	static bool isZeroStrictly(const float x) { return ::fabs(x) < getStrictTolerance(); }

	static bool isEqualStrictly(const float x, const float y) { return ::fabs(x - y) < getStrictTolerance(); }

	static float getHalfPI() { return 0.5f * getPI(); }

	static float getPI() { return 3.14159265359f; }

	static float getTwoPI() { return 2.0f * getPI(); }
};

template<>
class Tolerance < double > final
{
public:
	static double getLooseTolerance() {
		return 1.0e-9;
	}

	static double getStrictTolerance() {
		return 1.0e-18;
	}

	static bool isEqual(const double x, const double y, const double tolerance) { return ::fabs(x - y) < tolerance; }

	static bool isZeroLoosely(const double x) { return ::fabs(x) < getLooseTolerance(); }

	static bool isEqualLoosely(const double x, const double y) { return ::fabs(x - y) < getLooseTolerance(); }

	static bool isZeroStrictly(const double x) { return ::fabs(x) < getStrictTolerance(); }

	static bool isEqualStrictly(const double x, const double y) { return ::fabs(x - y) < getStrictTolerance(); }

	static double getHalfPI() { return 0.5 * getPI(); }

	static double getPI() { return 3.141592653589793238462643383279; }

	static double getTwoPI() { return 2.0 * getPI(); }
};
	}
}

#endif
#include "Box3d.h"
#include <cassert>

using namespace Crystal::Math;

Box3d::Box3d()
	: Box3d(Vector3dd(0, 0, 0), Vector3dd(1, 1, 1))
{
}

Box3d::Box3d(const Vector3dd& point) :
	start(point),
	end(point)
{
}

Box3d::Box3d(const Vector3dd& pointX, const Vector3dd& pointY)
{
	const auto x = std::min<double>(pointX.x, pointY.x);
	const auto y = std::min<double>(pointX.y, pointY.y);
	const auto z = std::min<double>(pointX.z, pointY.z);
	this->start = Vector3dd(x, y, z);
	const auto endX = std::max<double>(pointX.x, pointY.x);
	const auto endY = std::max<double>(pointX.y, pointY.y);
	const auto endZ = std::max<double>(pointX.z, pointY.z);
	this->end = Vector3dd(endX, endY, endZ);
	assert(isValid());
}

void Box3d::add(const Vector3dd& v) {
	const auto x = std::min<double>(getMinX(), v.x);
	const auto y = std::min<double>(getMinY(), v.y);
	const auto z = std::min<double>(getMinZ(), v.z);
	start = Vector3dd(x, y, z);

	const auto endX = std::max<double>(end.x, v.x);
	const auto endY = std::max<double>(end.y, v.y);
	const auto endZ = std::max<double>(end.z, v.z);
	end = Vector3dd(endX, endY, endZ);
}

double Box3d::getVolume() const
{
	const auto& length = getLength();
	return length.x * length.y * length.z;
}

Vector3dd Box3d::getLength() const
{
	return Vector3dd(end.x - getMinX(), end.y - getMinY(), end.z - getMinZ());
}

bool Box3d::isInterior(const Vector3dd& point) const
{
	const bool xIsInterior = (getMinX() < point.x && point.x < end.x);
	const bool yIsInterior = (getMinY() < point.y && point.y < end.y);
	const bool zIsInterior = (getMinZ() < point.z && point.z < end.z);
	return xIsInterior && yIsInterior && zIsInterior;
}

bool Box3d::isExterior(const Vector3dd& point) const
{
	return !isInterior(point);
}

void Box3d::add(const Box3d& b)
{
	const auto sx = std::min<double>(getMinX(), b.getMinX());
	const auto sy = std::min<double>(getMinY(), b.getMinY());
	const auto sz = std::min<double>(getMinZ(), b.getMinZ());
	this->start = Vector3dd(sx, sy, sz);

	const auto ex = std::max<double>(end.x, b.getMaxX());
	const auto ey = std::max<double>(end.y, b.getMaxY());
	const auto ez = std::max<double>(end.z, b.getMaxZ());
	this->end = Vector3dd(ex, ey, ez);
}

Vector3dd Box3d::getCenter() const
{
	return Vector3dd(
		(getMinX() + end.x) / 2.0,
		(getMinY() + end.y) / 2.0,
		(getMinZ() + end.z) / 2.0
	);
}

Box3d Box3d::getOverlapped(const Box3d& rhs) const
{
	assert(hasIntersection(rhs));
	const auto minx = std::max<double>(this->getStart().x, rhs.getStart().x);
	const auto miny = std::max<double>(this->getStart().y, rhs.getStart().y);
	const auto minz = std::max<double>(this->getStart().z, rhs.getStart().z);

	const auto maxx = std::min<double>(this->getEnd().x, rhs.getEnd().x);
	const auto maxy = std::min<double>(this->getEnd().y, rhs.getEnd().y);
	const auto maxz = std::min<double>(this->getEnd().z, rhs.getEnd().z);

	const Vector3dd min_(minx, miny, minz);
	const Vector3dd max_(maxx, maxy, maxz);
	return Box3d(min_, max_);
}

bool Box3d::equals(const Box3d& rhs) const
{
	return
		start == rhs.getStart() &&
		Tolerance<double>::isEqualLoosely(end.x, rhs.end.x) &&
		Tolerance<double>::isEqualLoosely(end.y, rhs.end.y) &&
		Tolerance<double>::isEqualLoosely(end.z, rhs.end.z);
}

bool Box3d::hasIntersection(const Box3d& rhs) const
{
	const auto distx = std::fabs(getCenter().x - rhs.getCenter().x);
	const auto lx = getLength().x / 2.0 +rhs.getLength().x / 2.0;

	const auto disty = std::fabs(getCenter().y - rhs.getCenter().y);
	const auto ly = getLength().y / 2.0 +rhs.getLength().y / 2.0;

	const auto distz = std::fabs(getCenter().z - rhs.getCenter().z);
	const auto lz = getLength().z / 2.0 +rhs.getLength().z / 2.0;

	return (distx < lx && disty < ly && distz < lz);
}

bool Box3d::isValid() const
{
	return
		(getMinX() <= end.x) && (getMinY() <= end.y) && (getMinZ() <= end.z);
}

bool Box3d::isShirinked() const
{
	return
		(getMinX() == end.x) && (getMinY() == end.y) && (getMinZ() == end.z);
}

Vector3dd Box3d::getPosition(const Vector3dd& param) const
{
	const auto& length = getLength();
	const auto x = start.x + length.x * param.x;
	const auto y = start.y + length.y * param.y;
	const auto z = start.z + length.z * param.z;
	return Vector3dd(x, y, z);
}
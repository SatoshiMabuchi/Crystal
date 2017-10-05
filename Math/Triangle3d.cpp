#include "Triangle3d.h"

using namespace Crystal::Math;

template<typename T>
Vector3d<T> Triangle3d<T>::getNormal() const
{
	const auto v1 = vertices[1] - vertices[0];
	const auto v2 = vertices[2] - vertices[0];
	return v1.getOuterProduct(v2).getNormalized();
}

template<typename T>
T Triangle3d<T>::getArea() const
{
	const auto v1 = vertices[1] - vertices[0];
	const auto v2 = vertices[2] - vertices[0];
	return v1.getOuterProduct(v2).getLength() * T { 0.5 };
}



template class Triangle3d<float>;
template class Triangle3d<double>;
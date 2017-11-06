#include "Triangle3d.h"

using namespace Crystal::Math;

template<typename T>
Vector3dd Triangle3d<T>::getNormal() const
{
	const auto v1 = vertices[1] - vertices[0];
	const auto v2 = vertices[2] - vertices[0];
	return glm::normalize( glm::cross(v1, v2) );
}

template<typename T>
T Triangle3d<T>::getArea() const
{
	const auto v1 = vertices[1] - vertices[0];
	const auto v2 = vertices[2] - vertices[0];
	return glm::cross( v1, v2 ).length()  * T { 0.5 };
}



template class Triangle3d<float>;
template class Triangle3d<double>;
#pragma once

#include <vector>
#include <array>
#include "../Math/Vector3d.h"
#include "../Math/Triangle3d.h"

namespace Crystal {
	namespace Shape {

class TriangleFace
{
public:
	explicit TriangleFace(const std::array<Math::Vector3d<double>,3>& vertices) :
		vertices(vertices)
	{
		this->normal = toTriangle().getNormal();
	}

	TriangleFace(const std::array<Math::Vector3d<double>, 3>& vertices, const Math::Vector3d<double>& normal) :
		vertices(vertices),
		normal(normal)
	{}

	Math::Vector3d<double> getNormal() const { return normal; }

	std::array<Math::Vector3d<double>, 3> getVertices() const { return vertices; }

	Math::Triangle3d<double> toTriangle() const { return Math::Triangle3d<double>(vertices); }

private:
	std::array<Math::Vector3d<double>, 3> vertices;
	Math::Vector3d<double> normal;
};

class TriangleMesh
{
public:
	explicit TriangleMesh(const std::vector<TriangleFace>& faces) :
		faces(faces)
	{}

	std::vector<TriangleFace> getFaces() const { return faces; }

private:
	std::vector<TriangleFace> faces;
};
	}
}
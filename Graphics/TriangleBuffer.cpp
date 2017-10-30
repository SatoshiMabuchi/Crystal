#include "TriangleBuffer.h"
#include "../Shape/PolygonMesh.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::Shape;

TriangleBuffer::TriangleBuffer()
{
}

void TriangleBuffer::add(const PolygonMesh& polygon, Material* mat)
{
	//polygon.getVertices();
	const auto& faces = polygon.getFaces();
	std::vector<unsigned int> indices;
	for (auto f : faces) {
		indices.push_back(f->getV1()->getId());
		indices.push_back(f->getV2()->getId());
		indices.push_back(f->getV3()->getId());
	}
	TriangleBufferBlock block(indices, mat);
	blocks.push_back(block);
}

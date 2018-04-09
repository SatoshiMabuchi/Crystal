#ifndef __CRYSTAL_GRAPHICS_TRIANGLE_BUFFER_H__
#define __CRYSTAL_GRAPHICS_TRIANGLE_BUFFER_H__

#include "Buffer3d.h"
#include "Buffer1d.h"
#include "Buffer4d.h"
#include "Material.h"
#include "../Shape/PolygonMesh.h"

namespace Crystal {
	namespace Graphics {

class TriangleBufferBlock
{
public:
	TriangleBufferBlock(const std::vector<unsigned int>& indices, Material* material) :
		indices(indices),
		material(material)
	{}

	std::vector<unsigned int> getIndices() const { return indices; }

	Material* getMaterial() const { return material; }

private:
	std::vector<unsigned int> indices;
	Material* material;
};


class TriangleBuffer
{
public:
	TriangleBuffer() {}

	void add(const Shape::PolygonMesh& polygon, Material* mat = nullptr) {
		const auto& vertices = polygon.getVertices();
		for (auto v : vertices) {
			positions.add(v->getPosition());
		}
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

	Buffer3d<float> getPositions() const { return positions; }

	Buffer3d<float> getNormals() const { return normals; }

	Buffer3d<float> getTexCoords() const { return texCoords; }

	std::vector<TriangleBufferBlock> getBlocks() const { return blocks; }

private:
	Buffer3d<float> positions;
	Buffer3d<float> normals;
	Buffer3d<float> texCoords;
	std::vector<TriangleBufferBlock> blocks;
};
	}
}

#endif
#ifndef __CRYSTAL_GRAPHICS_TRIANGLE_BUFFER_H__
#define __CRYSTAL_GRAPHICS_TRIANGLE_BUFFER_H__

#include "Buffer3d.h"
#include "Buffer1d.h"
#include "Buffer4d.h"
#include "Material.h"

namespace Crystal {
	namespace Shape {
		class PolygonMesh;
	}
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
	TriangleBuffer();

	void add(const Shape::PolygonMesh& polygon, Material* mat = nullptr);

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
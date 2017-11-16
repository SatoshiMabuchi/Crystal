#ifndef __CRYSTAL_GRAPHICS_LINE_BUFFER_H__
#define __CRYSTAL_GRAPHICS_LINE_BUFFER_H__

#include "Buffer3d.h"
#include "Buffer1d.h"
#include "Buffer4d.h"

namespace Crystal {
	namespace Graphics {

class LineBuffer
{
public:
	LineBuffer() {};

	void clear() {
		positions.clear();
		colors.clear();
	}

	void add(const Math::Vector3df& position, const ColorRGBAf& color) {
		positions.add(position);
		colors.add(color);
	}

	Graphics::Buffer3d<float> getPositions() const { return positions; }

	Graphics::Buffer4d<float> getColors() const { return colors; }

	std::vector<unsigned int> getIndices() const { return indices; }

private:
	Graphics::Buffer3d<float> positions;
	Graphics::Buffer4d<float> colors;
	std::vector<unsigned int> indices;
};

	}
}

#endif
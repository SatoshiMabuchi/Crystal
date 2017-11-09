#ifndef __CRYSTAL_GRAPHICS_POINT_BUFFER_H__
#define __CRYSTAL_GRAPHICS_POINT_BUFFER_H__

#include "Buffer3d.h"
#include "Buffer1d.h"
#include "Buffer4d.h"

namespace Crystal {
	namespace Graphics {

class PointBuffer
{
public:
	PointBuffer() {};

	void clear();

	void add(const Math::Vector3df& position, const ColorRGBAf& color, const float size);

	void add(const Math::Vector3dd& position, const ColorRGBAf& color, const float size);

	Graphics::Buffer3d<float> getPosition() const { return position; }

	Graphics::Buffer4d<float> getColor() const { return color; }

	Graphics::Buffer1d<float> getSize() const { return sizes; }

private:
	Graphics::Buffer3d<float> position;
	Graphics::Buffer4d<float> color;
	Graphics::Buffer1d<float> sizes;
};

	}
}

#endif
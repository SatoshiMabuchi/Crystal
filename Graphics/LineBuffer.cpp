#include "LineBuffer.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;

void LineBuffer::clear()
{
	positions.clear();
	colors.clear();
}

void LineBuffer::add(const Vector3df& position, const ColorRGBAf& color)
{
	positions.add(position);
	colors.add(color);
}

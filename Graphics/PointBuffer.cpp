#include "PointBuffer.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;

void PointBuffer::add(const Vector3df& position, const ColorRGBAf& color, const float size)
{
	this->position.add(position);
	this->color.add(color);
	this->sizes.add(size);
}

void PointBuffer::add(const Vector3dd& position, const ColorRGBAf& color, const float size)
{
	this->position.add(position);
	this->color.add(color);
	this->sizes.add(size);
}


void PointBuffer::clear()
{
	position.clear();
	color.clear();
	sizes.clear();
}
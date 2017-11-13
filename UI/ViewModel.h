#pragma once

#include "../Graphics/PointBuffer.h"
#include "ParticleSystemObject.h"

namespace Crystal {
	namespace UI {

class ViewModel
{
public:
	void add(const Math::Vector3df& pos, const Graphics::ColorRGBAf& c, const float size);

	void add(const ParticleSystemObject& object);

	Graphics::PointBuffer getPointBuffer() const { return pointBuffer; }

private:
	Graphics::PointBuffer pointBuffer;
};
	}
}
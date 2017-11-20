#pragma once

#include "../Graphics/PointBuffer.h"
#include "../Graphics/LineBuffer.h"
#include "ParticleSystemObject.h"
#include "WireFrameObject.h"

namespace Crystal {
	namespace UI {

class ViewModel
{
public:
	void add(const Math::Vector3df& pos, const Graphics::ColorRGBAf& c, const float size);

	void add(const ParticleSystemObject& object);

	void add(const WireFrameObject& object);

	Graphics::PointBuffer getPointBuffer() const { return pointBuffer; }

	Graphics::LineBuffer getLineBuffer() const { return lineBuffer; }

private:
	Graphics::PointBuffer pointBuffer;
	Graphics::LineBuffer lineBuffer;
};
	}
}
#pragma once

#include "IObject.h"
#include "../Shape/ParticleSystem.h"
#include "../Graphics/ColorRGBA.h"

namespace Crystal {
	namespace UI {

struct ParticleAttr
{
	Graphics::ColorRGBA<float> color;
	float size;
};

class ParticleSystemObject : public IObject
{
public:
	explicit ParticleSystemObject(const int id, Shape::ParticleSystem<float, ParticleAttr>* shape) :
		IObject(id),
		shape(shape)
	{}

	~ParticleSystemObject() {};

	Shape::ParticleSystem<float, ParticleAttr>* getShape() const { return shape; }

private:
	Shape::ParticleSystem<float, ParticleAttr>* shape;
};

	}
}
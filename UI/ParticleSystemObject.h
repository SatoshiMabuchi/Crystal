#pragma once

#include "IObject.h"
#include "../Shape/ParticleSystem.h"
#include "../Graphics/ColorRGBA.h"

namespace Crystal {
	namespace UI {

struct ParticleAttr
{
	Graphics::ColorRGBAf color;
	float size;
};

class ParticleSystemObject : public IObject
{
public:
	explicit ParticleSystemObject(const int id, Shape::ParticleSystem<ParticleAttr>* shape) :
		IObject(id),
		shape(shape)
	{}

	~ParticleSystemObject() {};

	Shape::ParticleSystem<ParticleAttr>* getShape() const { return shape; }

private:
	Shape::ParticleSystem<ParticleAttr>* shape;
};

	}
}
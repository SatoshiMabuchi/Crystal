#pragma once

#include "IObject.h"
#include "../Shape/ParticleSystem.h"
#include "../Graphics/ColorRGBA.h"

namespace Crystal {
	namespace UI {

class ParticleSystemObject : public IObject
{
public:
	explicit ParticleSystemObject(const int id, Shape::ParticleSystem<double, Graphics::ColorRGBA<float>>* shape) :
		IObject(id),
		shape(shape)
	{}

	~ParticleSystemObject() {};

	Shape::ParticleSystem<double, Graphics::ColorRGBA<float>>* getShape() const { return shape; }

private:
	Shape::ParticleSystem<double, Graphics::ColorRGBA<float>>* shape;
};

	}
}
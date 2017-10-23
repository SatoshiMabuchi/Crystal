#pragma once

namespace Crystal {
	namespace UI {

class IObject
{
public:
	explicit IObject(const int id) :
		id(id)
	{}

	~IObject() {};

	int getId() const { return id; }
private:
	int id;
};

class ParticleSystemObject : public IObject
{
	explicit ParticleSystemObject(const int id) :
		IObject(id)
	{}

	~ParticleSystemObject() {};

private:
	//Shape::ParticleSystem<double, Graphics::ColorRGBA<float>>* particleSystem;
};
	}
}
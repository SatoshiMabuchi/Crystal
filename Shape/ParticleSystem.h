#pragma once

#include "../Math/Vector3d.h"

namespace Crystal {
	namespace Shape {

template <typename T, typename Attr>
class Particle
{
public:
	Particle(const Math::Vector3d<T>& position, const Attr& attr) :
		position(position),
		attribute(attr)
	{}

	Math::Vector3d<T> getPosition() const { return position; }

private:
	Math::Vector3d<T> position;
	Attr attribute;
};

template<typename T, typename Attr>
class ParticleSystem
{
public:
	ParticleSystem() {}

	~ParticleSystem() {
		clear();
	}

	void clear() {
		for (auto p : particles) {
			delete p;
		}
		particles.clear();
	}
	
	void add(const Math::Vector3d<T>& position, const Attr& attr) {
		particles.push_back(new Particle<T,Attr>(position, attr));
	}

private:
	std::vector<Particle<T,Attr>*> particles;
};
	}
}
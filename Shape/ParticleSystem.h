#ifndef __CRYSTAL_SHAPE_PARTICLE_SYSTEM_H__
#define __CRYSTAL_SHAPE_PARTICLE_SYSTEM_H__

#include "../Math/Vector3d.h"
#include "../Math/Box3d.h"

namespace Crystal {
	namespace Shape {

template<typename Attr>
class Particle
{
public:
	Particle(const Math::Vector3dd& position, const Attr& attr) :
		position(position),
		attribute(attr)
	{}

	Math::Vector3dd getPosition() const { return position; }

	Attr getAttribute() const { return attribute; }

private:
	Math::Vector3dd position;
	Attr attribute;
};

template<typename Attr>
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
	
	void add(const Math::Vector3dd& position, const Attr& attr) {
		particles.push_back(new Particle<Attr>(position, attr));
	}

	std::vector<Particle<Attr>*> getParticles() const { return particles; }

	Math::Box3d getBoundingBox() {
		if (particles.empty()) {
			return Math::Box3d();
		}
		Math::Box3d bb(particles.front()->getPosition());
		for (auto p : particles) {
			bb.add(p->getPosition());
		}
		return bb;
	}

private:
	std::vector<Particle<Attr>*> particles;
};
	}
}

#endif
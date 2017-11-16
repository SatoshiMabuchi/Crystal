#include "ObjectRepository.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

int ObjectRepository::addParticleSystem(const std::vector<Vector3df>& positions, const ColorRGBAf& color, const float size)
{
	auto particles = new Shape::ParticleSystem<ParticleAttr>();
	for (const auto& p : positions) {
		ParticleAttr attr;
		attr.color = color;
		attr.size = size;
		particles->add(p, attr);
	}
	particleSystems.push_back(ParticleSystemObject(nextId++, particles));
	return particleSystems.back().getId();
}

int ObjectRepository::addWireFrame(WireFrame* wire, const ColorRGBAf& color)
{
	wires.push_back(WireFrameObject(nextId++, wire));
	return wires.back().getId();
}

Box3d ObjectRepository::getBoundingBox() const
{
	if (particleSystems.empty()) {
		return Box3d();
	}
	Box3d bb(particleSystems.front().getShape()->getBoundingBox());
	for (const auto& p : particleSystems) {
		bb.add(p.getShape()->getBoundingBox());
	}
	return bb;
}


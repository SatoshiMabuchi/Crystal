#pragma once

#include "ParticleSystemObject.h"
#include "PolygonMeshObject.h"
#include "WireFrameObject.h"

namespace Crystal {
	namespace UI {

class ObjectRepository
{
public:
	ObjectRepository() :
		nextId(1)
	{}

	int addParticleSystem(const std::vector<Math::Vector3df>& positions, const Graphics::ColorRGBAf& color, const float size);

	std::list<ParticleSystemObject> getParticleSystems() const { return particleSystems; }

	int addWireFrame(Shape::WireFrame* wire, const Graphics::ColorRGBAf& color);

	Math::Box3d getBoundingBox() const;

private:
	int nextId;
	std::list<ParticleSystemObject> particleSystems;
	std::list<PolygonMeshObject> polygonMeshes;
	std::list<WireFrameObject> wires;
};
	}
}
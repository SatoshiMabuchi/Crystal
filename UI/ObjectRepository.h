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

	int addWireFrame(Shape::WireFrame* wire, const Graphics::ColorRGBAf& color);

	int addPolygonMesh(Shape::PolygonMesh* mesh, const Graphics::Material& material);

	std::list<ParticleSystemObject> getParticleSystems() const { return particleSystems; }

	std::list<WireFrameObject> getWireFrames() const { return wires; }

	std::list<PolygonMeshObject> getPolygonMeshes() const { return polygonMeshes; }

	Math::Box3d getBoundingBox() const;

	std::list<Math::Vector3dd> getAllVertices() const;

private:
	int nextId;
	std::list<ParticleSystemObject> particleSystems;
	std::list<WireFrameObject> wires;
	std::list<PolygonMeshObject> polygonMeshes;
};
	}
}
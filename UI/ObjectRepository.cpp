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
	wires.push_back(WireFrameObject(nextId++, wire, color));
	return wires.back().getId();
}

int ObjectRepository::addPolygonMesh(PolygonMesh* mesh, const ColorRGBAf& color)
{
	polygonMeshes.push_back(PolygonMeshObject(nextId++, mesh, color));
	return polygonMeshes.back().getId();
}

Box3d ObjectRepository::getBoundingBox() const
{
	const auto& vertices = getAllVertices();
	if (vertices.empty()) {
		return Box3d();
	}
	Box3d bb(vertices.front());
	for (const auto& v : vertices) {
		bb.add(v);
	}
	return bb;
}

std::list<Vector3dd> ObjectRepository::getAllVertices() const
{
	std::list<Vector3dd> positions;
	for (const auto& ps : particleSystems) {
		const auto& particles = ps.getShape()->getParticles();
		for (const auto& p : particles) {
			positions.push_back( p->getPosition() );
		}
	}
	for (const auto& ws : wires) {
		const auto& vs = ws.getShape()->getVertices();
		positions.insert(positions.end(), vs.begin(), vs.end());
	}
	for (const auto& ps : polygonMeshes) {
		const auto& vs = ps.getShape()->getVertices();
		for (const auto& p : vs) {
			positions.push_back(p->getPosition());
		}
	}
	return positions;
}

#include "ViewModel.h"
#include "IModel.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

void ViewModel::add(const Vector3df& pos, const ColorRGBAf& c, const float size)
{
	pointBuffer.add(pos, c, size);
}

void ViewModel::add(const ParticleSystemObject& object)
{
	const auto& particles = object.getShape()->getParticles();
	for (auto p : particles) {
		pointBuffer.add( p->getPosition(), p->getAttribute().color, p->getAttribute().size);
	}
}

void ViewModel::add(const WireFrameObject& object)
{
	const auto& lines = object.getShape()->getLines();
	const auto& color = object.getColor();
	int index = 0;
	for (const auto& l : lines) {
		lineBuffer.add(l.getStart(), color, index++);
		lineBuffer.add(l.getEnd(), color, index++);
	}
}

void ViewModel::add(const PolygonMeshObject& object)
{
	auto material = object.getMaterial();
	triangleBuffer.add(*object.getShape(), material);

	/*
	const auto& vertices =  object.getShape()->getVertices();
	for (auto l : vertices) {
		triangleBuffer.add(*object.getShape());
	}
	*/
}


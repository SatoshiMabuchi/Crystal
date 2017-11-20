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
	int index = 0;
	for (const auto& l : lines) {
		lineBuffer.add(l.getStart(), ColorRGBAf(1, 1, 1, 1), index++);
		lineBuffer.add(l.getEnd(), ColorRGBAf(1, 1, 1, 1), index++);

	}
}

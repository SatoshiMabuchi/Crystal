#include "ViewModel.h"
#include "IModel.h"

using namespace Crystal::Graphics;
using namespace Crystal::UI;

void ViewModel::add(const ParticleSystemObject& object)
{
	const auto& particles = object.getShape()->getParticles();
	for (auto p : particles) {
		pointBuffer.add( p->getPosition(), p->getAttribute().color, p->getAttribute().size);
	}
}
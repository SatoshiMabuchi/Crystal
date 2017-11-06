#pragma once

#include "../Shape/ParticleSystem.h"
#include "../Shape/PolygonMesh.h"
#include "IObject.h"
#include "ParticleSystemObject.h"
#include "ViewModel.h"

namespace Crystal {
	namespace UI {

class IModel
{
public:
	bool read(const std::string& filename);

	bool write(const std::string& filename) const;

	int addParticleSystem(const std::vector<Math::Vector3df>& positions, const Graphics::ColorRGBA<float>& color, const float size);

	std::list<ParticleSystemObject> getParticleSystems() const { return particleSystems; }

	ViewModel toViewModel() const;

private:	
	Shape::PolygonMesh* polygonMesh;
	std::list<ParticleSystemObject> particleSystems;
	int nextId;
};
	}
}
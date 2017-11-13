#pragma once

#include "ObjectRepository.h"
#include "ViewModel.h"

namespace Crystal {
	namespace UI {

class IModel
{
public:
	bool read(const std::string& filename);

	bool write(const std::string& filename) const;

	int addParticleSystem(const std::vector<Math::Vector3df>& positions, const Graphics::ColorRGBAf& color, const float size);

	std::list<ParticleSystemObject> getParticleSystems() const { return objects.getParticleSystems(); }

	virtual ViewModel toViewModel() const;

	virtual Math::Box3d getBoundingBox() const;

private:	
	ObjectRepository objects;
	int nextId;
};
	}
}
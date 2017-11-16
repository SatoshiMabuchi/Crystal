#pragma once

#include "ObjectRepository.h"
#include "ViewModel.h"
#include "../Shape/WireFrame.h"

namespace Crystal {
	namespace UI {

class IModel
{
public:
	virtual ~IModel() {}

	bool read(const std::string& filename);

	bool write(const std::string& filename) const;

	int addParticleSystem(const std::vector<Math::Vector3df>& positions, const Graphics::ColorRGBAf& color, const float size);

	std::list<ParticleSystemObject> getParticleSystems() const { return objects.getParticleSystems(); }

	int addWireFrame(Shape::WireFrame* wire, const Graphics::ColorRGBAf& color);

	virtual ViewModel toViewModel() const;

	virtual Math::Box3d getBoundingBox() const;

private:	
	ObjectRepository objects;
};
	}
}
#pragma once

#include "../Shape/ParticleSystem.h"
#include "../Shape/PolygonMesh.h"
#include "IObject.h"
#include "ParticleSystemObject.h"

namespace Crystal {
	namespace UI {

class IModel
{
public:
	bool read(const std::string& filename);

	bool write(const std::string& filename) const;

	int addParticleSystem(const std::vector<Math::Vector3d<double>>& positions, const Graphics::ColorRGBA<float>& color);

private:	
	Shape::PolygonMesh* polygonMesh;
	std::list<ParticleSystemObject> particleSystems;
	int nextId;
};
	}
}
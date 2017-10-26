#pragma once

#include "../Shape/ParticleSystem.h"
#include "../Shape/PolygonMesh.h"
#include "IObject.h"

namespace Crystal {
	namespace UI {

class IModel
{
public:
	bool read(const std::string& filename);

	bool write(const std::string& filename) const;

	int addParticleSystem(const std::vector<Math::Vector3d<double>>& positions);

private:	
	Shape::PolygonMesh* polygonMesh;
};
	}
}
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

private:
	
	Shape::PolygonMesh* polygonMesh;
};
	}
}
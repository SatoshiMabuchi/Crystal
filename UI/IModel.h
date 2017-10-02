#pragma once

#include "../Shape/PolygonMesh.h"

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
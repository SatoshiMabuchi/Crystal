#pragma once

#include "../Shape/TriangleMesh.h"

namespace Crystal {
	namespace IO {

class STLAsciiFileWriter
{
public:
	explicit STLAsciiFileWriter(const Shape::TriangleMesh& mesh);

	bool write(const std::string& filename);

	bool write(std::ostream& stream);

private:
	std::string title;
	Shape::TriangleMesh mesh;
};
	}
}
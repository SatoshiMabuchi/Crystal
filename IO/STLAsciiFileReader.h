#ifndef __CRYSTAL_IO_STL_ASCII_FILE_READER_H__
#define __CRYSTAL_IO_STL_ASCII_FILE_READER_H__

#include "../Shape/TriangleMesh.h"

#include <fstream>

#include <vector>

namespace Crystal {
	namespace Shape {
		class PolygonMesh;
	}
	namespace IO {

class STLAsciiFileReader
{
public:
	STLAsciiFileReader()
	{}

	bool read(const std::string& filename);

	bool read(std::istream& stream);

	std::vector<Shape::TriangleFace> getFaces() const { return faces; }

private:
	std::vector<Shape::TriangleFace> faces;
	std::string title;
};

	}
}

#endif
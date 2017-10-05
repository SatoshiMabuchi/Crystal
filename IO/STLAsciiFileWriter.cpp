#include "STLAsciiFileWriter.h"
#include <fstream>

using namespace Crystal::IO;

bool STLAsciiFileWriter::write(const std::string& filename)
{
	std::ofstream stream(filename);
	if (!stream.is_open()) {
		return false;
	}
	return write(stream);
}

bool STLAsciiFileWriter::write(std::ostream& stream)
{
	stream << "solid" << " " << title.c_str() << std::endl;

	const auto& faces = mesh.getFaces();
	for (const auto& face : faces) {
		stream << "facet" << " ";
		const auto& normal = face.getNormal();
		stream << "normal" << " " << normal.getX() << " " << normal.getY() << " " << normal.getZ() << std::endl;
		stream << "outer loop" << std::endl;
		const auto& positions = face.getVertices();
		for (const auto& pos : positions) {
			stream << "vertex" << " " << pos.getX() << " " << pos.getY() << " " << pos.getZ() << std::endl;
		}
		stream << "endloop" << std::endl;
		stream << "endfacet" << std::endl;
	}
	stream << "endsolid" << std::endl;

	return stream.good();
}
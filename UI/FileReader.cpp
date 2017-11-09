#include "FileReader.h"

#include <filesystem>

#include "../IO/OBJFileReader.h"
#include "../IO/DXFFileReader.h"
#include "../IO/STLAsciiFileReader.h"

using namespace Crystal::IO;
using namespace Crystal::UI;

bool FileReader::read(const std::string& filename)
{
	const auto& ext = std::experimental::filesystem::path(filename).extension();
	if (ext == ".obj") {
		OBJFileReader reader;
		if (reader.read(filename)) {
			;
			return true;
		}
		return false;
	}
	else if (ext == ".dxf") {
		DXFFileReader reader;
		return reader.read(filename);
	}
	else if (ext == ".stl") {
		STLAsciiFileReader reader;
		return reader.read(filename);
	}
	return false;
}

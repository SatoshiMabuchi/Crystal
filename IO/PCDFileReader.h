#pragma once

#include <string>

namespace Crystal {
	namespace IO {

class PCDFileReader
{
	bool read(std::istream& stream);

	bool read(const std::string& filename);
};
	}
}
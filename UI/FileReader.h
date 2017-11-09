#pragma once

#include <string>
#include "ObjectRepository.h"

namespace Crystal {
	namespace UI {

class FileReader
{
public:
	bool read(const std::string& filename);

	ObjectRepository getObjects() const { return objects; }

private:
	ObjectRepository objects;
};
	}
}
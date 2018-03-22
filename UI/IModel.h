#pragma once

#include "ObjectRepository.h"
#include "ViewModel.h"
#include "../Shape/WireFrame.h"

namespace Crystal {
	namespace UI {

class IModel
{
public:
	virtual ~IModel() {}

	bool read(const std::string& filename);

	bool write(const std::string& filename) const;

	ObjectRepository* getRepository() { return &objects; }

	virtual ViewModel toViewModel() const;

	virtual Math::Box3d getBoundingBox() const;

private:	
	ObjectRepository objects;
};
	}
}
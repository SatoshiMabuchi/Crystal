#include "IModel.h"

#include "FileReader.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

bool IModel::read(const std::string& filename)
{
	FileReader reader;
	return reader.read(filename);
}

bool IModel::write(const std::string& filename) const
{
	//const auto& ext = std::experimental::filesystem::path(filename).extension();
	/*
	if (ext == ".obj") {
		OBJFileWriter reader;
		return reader.read(filename);
	}
	*/
	return false;
}

ViewModel IModel::toViewModel() const
{
	ViewModel vm;
	const auto& particleSystems = objects.getParticleSystems();
	for (const auto& p : particleSystems) {
		vm.add(p);
	}
	const auto& wires = objects.getWireFrames();
	for (const auto& w : wires) {
		vm.add(w);
	}

	return vm;
}

Box3d IModel::getBoundingBox() const
{
	return objects.getBoundingBox();
}

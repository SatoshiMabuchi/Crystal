#include "IModel.h"

#include <filesystem>

#include "../IO/OBJFileReader.h"
#include "../IO/DXFFileReader.h"
#include "../IO/STLAsciiFileReader.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::IO;
using namespace Crystal::UI;

bool IModel::read(const std::string& filename)
{
	const auto& ext = std::experimental::filesystem::path(filename).extension();
	if (ext == ".obj") {
		OBJFileReader reader;
		return reader.read(filename);
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

bool IModel::write(const std::string& filename) const
{
	const auto& ext = std::experimental::filesystem::path(filename).extension();
	/*
	if (ext == ".obj") {
		OBJFileWriter reader;
		return reader.read(filename);
	}
	*/
	return false;
}

int IModel::addParticleSystem(const std::vector<Vector3d<double>>& positions, const ColorRGBA<float>& color)
{
	auto particles = new Shape::ParticleSystem<double, Graphics::ColorRGBA<float>>();
	for (const auto& p : positions) {
		particles->add(p, color);
	}
	particleSystems.push_back(ParticleSystemObject(nextId++, particles));
	return particleSystems.back().getId();
}
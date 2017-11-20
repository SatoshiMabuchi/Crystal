#pragma once

#include "../Math/Line3d.h"
#include "../Math/Sphere3d.h"
#include "../Math/Box3d.h"
#include "WireFrame.h"

namespace Crystal {
	namespace Shape {

class WireFrameBuilder
{
public:
	/*
	void build(const Math::Box3d& box) {
		std::vector<std::vector<Math::Vector3dd>> grid;
		lines.push_back( Math::Line3dd( box.getPosition(Math::Vector3dd(0, 0, 0));
	}
	*/

	void build(const Math::Sphere3d& sphere) {
		std::vector<std::vector<Math::Vector3dd>> grid;
		for (auto u = 0.0; u < 1.0; u += 0.1) {
			std::vector<Math::Vector3dd> g;
			for (auto v = 0.0; v < 1.0; v += 0.1) {
				g.push_back( sphere.getPositionByParam(u, v) );
			}
			grid.push_back(g);
		}
	}

	void make(const std::vector<std::vector<Math::Vector3dd>>& grid) {
		for (int i = 0; i < grid.size()-1; ++i) {
			for (int j = 0; j < grid[i].size()-1; ++j) {
				lines.push_back(Math::Line3dd(grid[i][j], grid[i + 1][j]) );
				lines.push_back(Math::Line3dd(grid[i][j], grid[i][j+1]));
				lines.push_back(Math::Line3dd(grid[i+1][j], grid[i+1][j + 1]));
				lines.push_back(Math::Line3dd(grid[i][j+1], grid[i+1][j + 1]));
			}
		}
	}

	WireFrame* getWireFrame() const { return new WireFrame(lines); }

private:
	std::vector<Math::Line3dd> lines;
};
	}
}
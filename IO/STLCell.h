#ifndef __CRYSTAL_IO_STL_CELL_H__
#define __CRYSTAL_IO_STL_CELL_H__

#include <vector>
#include "../Math/Vector3d.h"

namespace Crystal {
	namespace IO {

class STLCell
{
public:
	STLCell()
	{}

	STLCell(const std::vector< Math::Vector3d<float> >& positions, const Math::Vector3d<float>& normal) :
		positions(positions),
		normal(normal)
	{}


	std::vector< Math::Vector3d<float> > getPositions() const { return positions; }

	void setPositions(const std::vector< Math::Vector3d<float> >& positions) { this->positions = positions; }

	void addPosition(const Math::Vector3d<float>& pos) { this->positions.push_back(pos); }

	void setNormal(const Math::Vector3d<float>& normal) { this->normal = normal; }

	Math::Vector3d<float> getNormal() const { return normal; }

	bool operator==(const STLCell& rhs) const {
		return
			positions == rhs.positions &&
			normal == rhs.normal;
	}


private:
	std::vector< Math::Vector3d<float> > positions;
	Math::Vector3d<float> normal;
};

using STLCellVector = std::vector< STLCell >;

	}
}

#endif // ! __CRYSTAL_IO_STL_CELL_H__

#ifndef __CRYSTAL_GRAPHICS_BUFFER_3D_H__
#define __CRYSTAL_GRAPHICS_BUFFER_3D_H__

#include "IBuffer.h"

//#include "../Math/Vector2d.h"
#include "../Math/Vector3d.h"
#include "../ThirdParty/glm-0.9.8.5/glm/glm.hpp"

namespace Crystal {
	namespace Graphics {

template<typename T>
class Buffer3d : public IBuffer<T> {
public:
	Buffer3d() = default;

	Buffer3d(const std::vector<T>& buffer) :
		IBuffer(buffer)
	{}

	~Buffer3d() = default;

	void add(const glm::vec3& v) {
		buffer.push_back(v[0]);
		buffer.push_back(v[1]);
		buffer.push_back(v[2]);
	}

	void add(const Buffer3d<T>& rhs) {
		buffer.insert(buffer.end(), rhs.buffer.begin(), rhs.buffer.end());
	}

	Math::Vector3dd get(const unsigned int i) const {
		const auto x = buffer[i * 3];
		const auto y = buffer[i * 3 + 1];
		const auto z = buffer[i * 3 + 2];
		return Math::Vector3dd(x, y, z);
	}

	bool operator==(const Buffer3d<T>& rhs) { return buffer == rhs.buffer; }

	std::vector< T > get() const { return std::move(buffer); }


private:
};

	}
}

#endif
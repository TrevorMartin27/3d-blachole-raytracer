#pragma once

#include <vector>
#include <limits>

#include "hittable/hittable.hpp"

// TODO: Maybe specialize, so we can use an array
//   instead of a vector if size is known?
template<typename T>
struct Group {
	std::vector<T> children;

	virtual float distance(const Point3& point) const noexcept {
		float min_distance = std::numeric_limits<float>::max();

		for (const T& child : this->children) {
			const float distance = child.distance(point);

			if (distance < min_distance) {
				min_distance = distance;
			}
		}

		return min_distance;
	}
};

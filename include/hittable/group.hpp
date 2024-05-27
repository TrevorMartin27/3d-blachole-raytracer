#pragma once

#include <vector>
#include <limits>

#include "hittable/hittable.hpp"

// TODO: Maybe specialize, so we can use an array
//   instead of a vector if size is known?
template<typename T>
struct Group : public Hittable {
	std::vector<T> children;

	virtual std::optional<Hittable::Distance>
		distance(const Point3& point) const noexcept override final
	{
		std::optional<Hittable::Distance> min_distance;

		for (const T& child : this->children) {
			const auto distance = child.distance(point);

			if (
				distance.has_value() && (
						!min_distance.has_value() ||
						distance.value() < min_distance.value()
				)
			) {
				min_distance = distance;
			}
		}

		return min_distance;
	}
};

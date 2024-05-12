#pragma once

#include "types/vec.hpp"
#include "types/point.hpp"

// NOTE: I assume we don't need a 2D ray.
struct Ray {
	Point3 origin;

	Vec3 direction;

	Point3 at(float t) const noexcept;
};

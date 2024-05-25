#pragma once

#include "hittable/hittable.hpp"

#include "types/vec.hpp"
#include "types/point.hpp"

struct Plane : public Hittable {
	Point3 center;
	Vec3 normal;

	// NOTE: Because our step radius thing isn't quite
	//   correct. Should hopefully be fixed later.
	float thickness;

	Plane(Point3 center, Vec3 normal, float thickness) noexcept;

	virtual float distance(const Point3& point) const noexcept;

	static Plane FromPoints(
		const Point3& a, const Point3& b, const Point3& c,
		float thickness
	) noexcept;
};

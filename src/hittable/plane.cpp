#include "hittable/plane.hpp"

#include <cmath>

Plane::Plane(Point3 center, Vec3 normal, float thickness) noexcept
	: center(center), normal(normal), thickness(thickness) { }

float Plane::distance(const Point3& point) const noexcept {
	// NOTE: Via the notes for Section 1.3

	const Vec3 PS = point - this->center;

	return std::max(
		std::abs(PS * this->normal) - this->thickness,
		0.0f
	);
}

Plane Plane::FromPoints(const Point3& a, const Point3& b, const Point3& c, float thickness) noexcept {
	const Vec3 basis0 = b - a;
	const Vec3 basis1 = c - a;

	return Plane {
		a,
		Vec3::Cross(basis0, basis1).normalized(),
		thickness
	};
}

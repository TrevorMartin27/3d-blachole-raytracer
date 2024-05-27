#include "hittable/sphere.hpp"

#include <cmath>

#include "types/vec.hpp"

Sphere::Sphere(Point3 center, float radius) noexcept
	: center(center), radius(radius) { }

// TODO: I would like to have a distance squared function
std::optional<Hittable::Distance> Sphere::distance(const Point3& point) const noexcept {
	return Hittable::Distance {
		(this->center - point).magnitude() - this->radius
	};
}

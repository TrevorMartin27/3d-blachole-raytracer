#include "hittable/hittable.hpp"

#include "types/point.hpp"

struct Sphere : public Hittable {
	Point3 center;
	float radius;

	Sphere(Point3 center, float radius) noexcept;

	// NOTE: final is important, it allows the compiler
	// to optimize what would otherwise be a virtual function
	// call (if the object is known).

	virtual std::optional<Hittable::Distance>
		distance(const Point3& point) const noexcept override final;
};

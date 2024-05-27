#pragma once

#include <optional>

struct Point3;

struct Material;

struct Hittable {
	struct Distance {
		float distance;

		bool operator<(const Hittable::Distance& other) const noexcept;
	};

	virtual ~Hittable() = default;

	virtual std::optional<Hittable::Distance>
		distance(const Point3& point) const noexcept = 0;
};

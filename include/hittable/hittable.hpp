#pragma once

struct Point3;

struct Hittable {
	virtual float distance(const Point3& point) const noexcept = 0;
};

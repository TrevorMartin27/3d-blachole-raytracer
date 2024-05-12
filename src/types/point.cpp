#include "types/point.hpp"

// NOTE: We can't forward declare here
#include "types/vec.hpp"

// TODO: Make sure all these functions are SIMD-ed in most sane release
// settings.

Point2 Point2::operator+(const Vec2& rhs) const noexcept {
	return Point2 {
		this->x + rhs.x,
		this->y + rhs.y
	};
}

Point2 Point2::operator-(const Vec2& rhs) const noexcept {
	// TODO: Make sure this is inlined sanely

	return *this + (-rhs);
}

Vec2 Point2::operator-(const Point2& rhs) const noexcept {
	//      A        where A = lhs,
	//     ^               B = rhs
	//    /
	//   /
	//  /   <---- v
	// B

	return Vec2 {
		this->x - rhs.x,
		this->y - rhs.y
	};
}

// -------------------------------------------------------------------- //

Point3 Point3::operator+(const Vec3& rhs) const noexcept {
	return Point3 {
		this->x + rhs.x,
		this->y + rhs.y,
		this->z + rhs.z
	};
}

Point3 Point3::operator-(const Vec3& rhs) const noexcept {
	// TODO: Make sure this is inlined sanely

	return *this + (-rhs);
}

Vec3 Point3::operator-(const Point3& rhs) const noexcept {
	//      A        where A = lhs,
	//     ^               B = rhs
	//    /
	//   /
	//  /   <---- v
	// B

	return Vec3 {
		this->x - rhs.x,
		this->y - rhs.y,
		this->z - rhs.z
	};
}

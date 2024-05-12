#include "types/vec.hpp"

#include <cmath>

// TODO: Make sure all these functions are SIMD-ed in most sane release
// settings.

Vec2 Vec2::operator+(const Vec2& rhs) const noexcept {
	return Vec2 {
		this->x + rhs.x,
		this->y + rhs.y
	};
}

Vec2 Vec2::operator-(const Vec2& rhs) const noexcept {
	// TODO: Make sure this is inlined sanely

	return *this + (-rhs);
}

Vec2 Vec2::operator-() const noexcept {
	return Vec2 {
		-this->x,
		-this->y
	};
}

Vec2 Vec2::operator*(const float rhs) const noexcept {
	return Vec2 {
		this->x * rhs,
		this->y * rhs
	};
}

Vec2 Vec2::operator/(const float rhs) const noexcept {
	return Vec2 {
		this->x / rhs,
		this->y / rhs
	};
}

float Vec2::operator*(const Vec2& rhs) const noexcept {
	return (
		(this->x * rhs.x) +
		(this->y * rhs.y)
	);
}

float Vec2::magnitude() const noexcept {
	// TODO: Make sure this is inlining sanely

	return std::sqrt(*this * *this);
}

Vec2 Vec2::normalize() const noexcept {
	// TODO: Make sure THIS is inlining sanely

	return *this / this->magnitude();
}

Vec2 Vec2::Cross(const Vec2& vector0) noexcept {
	// cross v             = | i j | = bi - aj
	//   where v = ai + bj   | a b |

	return Vec2 {
		vector0.y,
		-vector0.x
	};
}

// -------------------------------------------------------------------- //

Vec3 Vec3::operator+(const Vec3& rhs) const noexcept {
	return Vec3 {
		this->x + rhs.x,
		this->y + rhs.y,
		this->z + rhs.z
	};
}

Vec3 Vec3::operator-(const Vec3& rhs) const noexcept {
	// TODO: Make sure this is inlined sanely

	return *this + (-rhs);
}

Vec3 Vec3::operator-() const noexcept {
	return Vec3 {
		-this->x,
		-this->y,
		-this->z
	};
}

Vec3 Vec3::operator*(const float rhs) const noexcept {
	return Vec3 {
		this->x * rhs,
		this->y * rhs,
		this->z * rhs
	};
}

Vec3 Vec3::operator/(const float rhs) const noexcept {
	return Vec3 {
		this->x / rhs,
		this->y / rhs,
		this->z / rhs
	};
}

float Vec3::operator*(const Vec3& rhs) const noexcept {
	return (
		(this->x * rhs.x) +
		(this->y * rhs.y) +
		(this->z * rhs.z)
	);
}

float Vec3::magnitude() const noexcept {
	// TODO: Make sure this is inlining sanely

	return std::sqrt(*this * *this);
}

Vec3 Vec3::normalize() const noexcept {
	// TODO: Make sure THIS is inlining sanely

	return *this / this->magnitude();
}

Vec3 Vec3::Cross(const Vec3& vector0, const Vec3& vector1) noexcept {
	// cross v, w                = | i j k | + (bf - ce)i - (af - cd)j + (ae - bd)k
	//   where v = ai + bj + ck,   | a b c |
	//         w = di + ej + fk    | d e f |

	return Vec3 {
		(vector0.y * vector1.z) - (vector0.z * vector1.y),
		(vector0.z * vector1.x) - (vector0.x * vector1.z), // Flipped
		(vector0.x * vector1.y) - (vector0.y * vector1.x),
	};
}

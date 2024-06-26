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

Vec2& Vec2::operator+=(const Vec2& rhs) noexcept {
	// TODO: See if we can do this cleaner

	this->x += rhs.x;
	this->y += rhs.y;

	return *this;
}

Vec2& Vec2::operator-=(const Vec2& rhs) noexcept {
	// TODO: See if we can do this cleaner

	this->x -= rhs.x;
	this->y -= rhs.y;

	return *this;
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

Vec2& Vec2::operator*=(const float rhs) noexcept {
	// TODO: See if we can do this cleaner

	this->x *= rhs;
	this->y *= rhs;

	return *this;
}

Vec2& Vec2::operator/=(const float rhs) noexcept {
	// TODO: See if we can do this cleaner

	this->x /= rhs;
	this->y /= rhs;

	return *this;
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

Vec2 Vec2::normalized() const noexcept {
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

float Vec2::Angle(const Vec2& vector0, const Vec2& vector1) noexcept {
	const float dot = vector0 * vector1;

	return std::acos(dot / (vector0.magnitude() * vector1.magnitude()));
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

Vec3& Vec3::operator+=(const Vec3& rhs) noexcept {
	// TODO: See if we can do this cleaner

	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;

	return *this;
}

Vec3& Vec3::operator-=(const Vec3& rhs) noexcept {
	// TODO: See if we can do this cleaner

	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;

	return *this;
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

Vec3& Vec3::operator*=(const float rhs) noexcept {
	// TODO: See if we can do this cleaner

	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;

	return *this;
}

Vec3& Vec3::operator/=(const float rhs) noexcept {
	// TODO: See if we can do this cleaner

	this->x /= rhs;
	this->y /= rhs;
	this->y /= rhs;

	return *this;
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

Vec3 Vec3::normalized() const noexcept {
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

float Vec3::Angle(const Vec3& vector0, const Vec3& vector1) noexcept {
	const float dot = vector0 * vector1;

	return std::acos(dot / (vector0.magnitude() * vector1.magnitude()));
}

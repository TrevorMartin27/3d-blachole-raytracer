#pragma once

struct Vec2 {
	float x;
	float y;

	// Vector Addition and Subtraction
	Vec2 operator+(const Vec2& rhs) const noexcept;
	Vec2 operator-(const Vec2& rhs) const noexcept;

	// Vector Negation
	Vec2 operator-() const noexcept;

	// Vector Scaling
	Vec2 operator*(const float rhs) const noexcept;
	Vec2 operator/(const float rhs) const noexcept;

	// Dot Product
	float operator*(const Vec2& rhs) const noexcept;

	// Length Operations
	float magnitude() const noexcept;
	Vec2 normalize() const noexcept;

	// Cross Product
	static Vec2 Cross(const Vec2& vector0) noexcept;
};

struct Vec3 {
	float x;
	float y;
	float z;

	// Vector Addition and Subtraction
	Vec3 operator+(const Vec3& rhs) const noexcept;
	Vec3 operator-(const Vec3& rhs) const noexcept;

	// Vector Negation
	Vec3 operator-() const noexcept;

	// Vector Scaling
	Vec3 operator*(const float rhs) const noexcept;
	Vec3 operator/(const float rhs) const noexcept;

	// Dot Product
	float operator*(const Vec3& rhs) const noexcept;

	// Length Operations
	float magnitude() const noexcept;
	Vec3 normalize() const noexcept;

	// Cross Product
	static Vec3 Cross(const Vec3& vector0, const Vec3& vector1) noexcept;
};

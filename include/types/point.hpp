#pragma once

// NOTE: We're using seperate types for points for two reasons:
//   1. Ease of readability (could be done with using or typedef)
//   2. To ensure we aren't doing any weird operations (limit ourselves
//      using the type system).

// NOTE: Forward declaration for compilation speed.
struct Vec2;

struct Point2 {
	float x;
	float y;

	// TODO: May need to enable explicit type casting to Vec2

	// Moving a point by adding/subtracting a vector
	Point2 operator+(const Vec2& rhs) const noexcept;
	Point2 operator-(const Vec2& rhs) const noexcept;

	Point2& operator+=(const Vec2& rhs) noexcept;
	Point2& operator-=(const Vec2& rhs) noexcept;

	// Finding the transition vector between two points
	Vec2 operator-(const Point2& rhs) const noexcept;

	// Convert to a vector
	Vec2 vec() const noexcept;

	static Point2 Origin() noexcept;
};

// NOTE: Forward declaration for compilation speed.
struct Vec3;

struct Point3 {
	float x;
	float y;
	float z;

	// TODO: May need to enable explicit type casting to Vec3

	// Moving a point by adding/subtracting a vector
	Point3 operator+(const Vec3& rhs) const noexcept;
	Point3 operator-(const Vec3& rhs) const noexcept;

	Point3& operator+=(const Vec3& rhs) noexcept;
	Point3& operator-=(const Vec3& rhs) noexcept;

	// Finding the transition vector between two points
	Vec3 operator-(const Point3& rhs) const noexcept;

	// Convert to a vector
	Vec3 vec() const noexcept;

	static Point3 Origin() noexcept;
};

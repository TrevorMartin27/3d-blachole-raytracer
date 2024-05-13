#pragma once

#include <limits>
#include <type_traits>

// TODO: Enforce that T must be a float or integer
template<typename T>
struct Interval {
	T min;
	T max;

	bool containsInclusive(const T value) const noexcept {
		return (
			(value >= this->min) &&
			(value <= this->max)
		);
	}

	bool containsExclusive(const T value) const noexcept {
		return (
			(value > this->min) &&
			(value < this->max)
		);
	}

	static Interval Positive() noexcept {
		return Interval<T> {
			0,
			std::numeric_limits<T>::max()
		};
	}
};

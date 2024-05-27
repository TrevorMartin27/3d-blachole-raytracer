#include "hittable/hittable.hpp"

bool Hittable::Distance::operator<(const Hittable::Distance& other) const noexcept {
	return this->distance < other.distance;
}

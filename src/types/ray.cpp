#include "types/ray.hpp"

#include "types/vec.hpp"
#include "types/point.hpp"

Point3 Ray::at(float t) const noexcept {
	return this->origin + (this->direction * t);
}

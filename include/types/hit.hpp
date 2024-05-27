#pragma once

#include <variant>

namespace HitType {
	struct Miss {};

	struct Captured {
		float distance_traveled;

		unsigned int step_count;
	};

	struct Hit {
		float distance_traveled;

		unsigned int step_count;
	};
};

using Hit = std::variant<
	HitType::Miss,
	HitType::Captured,
	HitType::Hit
>;

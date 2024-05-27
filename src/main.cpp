#include <iostream>
#include <vector>
#include <optional>
#include <limits>

#include <cmath>

#include "types/vec.hpp"
#include "types/point.hpp"
#include "types/ray.hpp"

#include "types/color.hpp"
#include "types/image.hpp"

#include "hittable/sphere.hpp"
#include "hittable/plane.hpp"
#include "hittable/group.hpp"

const float G = 1.0f;
const float c = 1.0f;
const float M = 1.0f;

const float SchwarzschildRadius = (2.0f * G * M) / (c * c);

const float IntersectionThreshold = 0.001f;
const float MaxDistance = 100.0f;
const float DeltaPhi = 0.01f;
const unsigned int MaxIterations = 5000;

struct Scene : public Hittable {
	Group<Sphere> spheres;
	Group<Plane> planes;

	virtual float distance(const Point3& point) const noexcept {
		float min_distance = std::numeric_limits<float>::max();

		// NOTE: I hate this, but I'm a C programmer. Improve.
#define REFINE_DISTANCE(C) \
		{ \
			const float distance = this->C.distance(point); \
			if (distance < min_distance) { \
				min_distance = distance; \
			} \
		}

		REFINE_DISTANCE(spheres);
		REFINE_DISTANCE(planes);

#undef REFINE_DISTANCE

		return min_distance;
	}
};

struct Hit {
	bool captured;

	float distance_traveled;
	unsigned int step_count;
};

template<typename T>
std::optional<Hit> march(Ray ray, const T& object) {
	// Setup the basis vectors (only care about Bx and By - horizontal plane)
	const auto Bx = ray.origin.vec().normalized();
	const auto Bz = Vec3::Cross(Bx, ray.direction).normalized();
	const auto By = Vec3::Cross(Bx, Bz).normalized(); // Shouldn't need to be normalized

	// Initial distance and angle
	const float R = ray.origin.vec().magnitude();
	const float beta = M_PI - Vec3::Angle(ray.origin.vec(), ray.direction);

	// Initial conditions
	float u = 1.0f / R, du = 1.0f / (R * std::tan(beta));

	// Make sure we don't spiral infinitely
	unsigned int step_count = 0, iterations = 0;

	// Because we start at phi=0 (based on Bx)
	float phi = 0.0f;
	for (float distance_traveled = 0.0f; distance_traveled < MaxDistance;) {
		// Find the distance we can savely travel
		const float distance_to_object =
			object.distance(
				Point3::Origin()
					+ Bx * (std::cos(phi) / u)
					+ By * (std::sin(phi) / u)
			);

		// Not handling NaNs right now (only once a frame)
		if (std::isnan(distance_to_object)) {
			std::cout << "NAN\n";

			return std::nullopt;
		}

		// Check if we hit an object (point very close)
		if (distance_to_object < IntersectionThreshold) {
			return Hit {
				false,
				distance_traveled,
				step_count
			};
		}

		// Move through the safe area
		// NOTE (tjm): This is not correct. Needed to add thickness
		// to planes.
		float local_distance_traveled;
		for (
			local_distance_traveled = 0.0f;
			local_distance_traveled < distance_to_object;
		) {
			// Acceleration
			const float ddu = ((3.0f * G * M) / (c * c)) * (u * u) - u;

			// New distance (angle = phi + DeltaPhi)
			const float nu = u + du * DeltaPhi;

			// Use law of cosines to find the distance traveled
			// This is an approximation, and will be less than the actual
			//   distance, which is fine
			{
				// TODO: This may not be correct
				const float d = 1.0f / u, nd = 1.0f / nu; 

				// Check if the point is in the inescapable radius
				if (d < SchwarzschildRadius) {
					return Hit {
						true,
						distance_traveled,
						step_count
					};
				}

				local_distance_traveled += std::sqrt(
					(d * d) + (nd * nd) - (2.0f * d * nd) * std::cos(DeltaPhi)
				);
			}

			// Change velocity
			du += ddu * DeltaPhi;
			u = nu; // Change u to the new u

			// Add to phi
			phi += DeltaPhi;

			// Increment interations, and check if we ran away
			iterations++;

			if (iterations > MaxIterations) {
				std::cerr << "[WARN] Max iterations hit.\n";

				return std::nullopt; // IDK
			}
		}

		// Update how far we've gone, and add step count
		distance_traveled += local_distance_traveled;
		step_count++;
	}

	return std::nullopt;
}

int main(int argc, const char* argv[]) {
	(void) argc, (void) argv;

	Image output = Image::Create(512, 512); // 512, 512

	Scene scene;
	scene.spheres.children.emplace_back(
		Point3 { 2.0f, 0.0f, -3.0f },
		1.0f
	);
	scene.planes.children.emplace_back(
		Point3 { 0.0f, 3.0f, 0.0f },
		Vec3 { 0.0f, 1.0f, 0.0f },
		0.25f
	);

	std::cerr << "[START]\n";
	std::cerr << "\tSchwarzchild Radius: " << SchwarzschildRadius << "\n";

	Ray ray = {
		Point3 {
			0.0f, 0.0f, -10.0f
		},

		Vec3 {
			0.0f, 0.0f, 1.0f
		}
	};

	// BUG: Output seems to be horizontally and vertically mirrored
	for (unsigned int y = 0; y < output.getHeight(); y++) {
		ray.direction.y = (static_cast<float>(y) / static_cast<float>(output.getHeight())) * 2.0f - 1.0f;

		for (unsigned int x = 0; x < output.getWidth(); x++) {
			ray.direction.x = (static_cast<float>(x) / static_cast<float>(output.getWidth())) * 2.0f - 1.0f;

			const auto hit = march(ray, scene);

			output.at(x, y) = Image::Pixel::FromColor(
				hit.has_value()
					? hit.value().captured
						? Color::Black()
						: Color::Red()
					: Color::Blue()
			);
		}

		if ((y % 100) == 0) {
			std::cerr << "Row " << y << "\n";
		}
	}

	output.save<Image::Format::PNG>("./output.png");

	std::cerr << "[DONE]\n";

	return 0;
}

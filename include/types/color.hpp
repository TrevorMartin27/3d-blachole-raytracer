#pragma once

struct Color {
	float red;
	float green;
	float blue;

	// NOTE: Not doing alpha for now

	static Color Black() noexcept;
	static Color White() noexcept;

	static Color Red() noexcept;
	static Color Green() noexcept;
	static Color Blue() noexcept;

	static Color Magenta() noexcept;
	static Color Cyan() noexcept;
	static Color Yellow() noexcept;
};

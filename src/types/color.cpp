#include "types/color.hpp"

Color Color::Black() noexcept {
	return Color { 0.0f, 0.0f, 0.0f };
}

Color Color::White() noexcept {
	return Color { 1.0f, 1.0f, 1.0f };
}

Color Color::Red() noexcept {
	return Color { 1.0f, 0.0f, 0.0f };
}

Color Color::Green() noexcept {
	return Color { 0.0f, 1.0f, 0.0f };
}

Color Color::Blue() noexcept {
	return Color { 0.0f, 0.0f, 1.0f };
}

Color Color::Magenta() noexcept {
	return Color { 1.0f, 0.0f, 1.0f };
}

Color Color::Cyan() noexcept {
	return Color { 0.0f, 1.0f, 1.0f };
}

Color Color::Yellow() noexcept {
	return Color { 1.0f, 1.0f, 0.0f };
}

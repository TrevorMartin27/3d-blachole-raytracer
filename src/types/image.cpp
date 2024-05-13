#include "types/image.hpp"

#include <string>
#include <stdexcept>

#include <cstdint>
#include <cassert>

#include "stb/stb_image_write.h"

#include "types/color.hpp"

Image::Pixel Image::Pixel::FromColor(Color color) noexcept {
	assert(color.red >= 0.0f);
	assert(color.red <= 1.0f);

	assert(color.green >= 0.0f);
	assert(color.green <= 1.0f);

	assert(color.blue >= 0.0f);
	assert(color.blue <= 1.0f);

	return Image::Pixel {
		static_cast<std::uint8_t>(color.red * 0xff),
		static_cast<std::uint8_t>(color.green * 0xff),
		static_cast<std::uint8_t>(color.blue * 0xff),
		0xff
	};
}

Image::Pixel Image::Pixel::Black() noexcept {
	return Image::Pixel::FromColor(Color::Black());
}

Image::Pixel Image::Pixel::White() noexcept {
	return Image::Pixel::FromColor(Color::White());
}

Image::Pixel Image::Pixel::Red() noexcept {
	return Image::Pixel::FromColor(Color::Red());
}

Image::Pixel Image::Pixel::Green() noexcept {
	return Image::Pixel::FromColor(Color::Green());
}

Image::Pixel Image::Pixel::Blue() noexcept {
	return Image::Pixel::FromColor(Color::Blue());
}

Image::Pixel Image::Pixel::Magenta() noexcept {
	return Image::Pixel::FromColor(Color::Magenta());
}

Image::Pixel Image::Pixel::Cyan() noexcept {
	return Image::Pixel::FromColor(Color::Cyan());
}

Image::Pixel Image::Pixel::Yellow() noexcept {
	return Image::Pixel::FromColor(Color::Yellow());
}

Image::Pixel Image::Pixel::Default() noexcept {
	return Image::Pixel::Magenta();
}

// -------------------------------------------------------------------- //

Image::Image(unsigned int width, unsigned int height, Pixel* pixels) noexcept
	: m_width(width)
	, m_height(height)
	, m_data(pixels)
{ }

Image::~Image() noexcept {
	delete[] this->m_data;
}

unsigned int Image::getWidth() const noexcept {
	return this->m_width;
}

unsigned int Image::getHeight() const noexcept {
	return this->m_height;
}

bool Image::contains(unsigned int x, unsigned int y) const noexcept {
	return (
		(x < this->getWidth()) &&
		(y < this->getHeight())
	);
}

Image::Pixel& Image::at(unsigned int x, unsigned int y) noexcept {
	assert(this->contains(x, y));

	return this->m_data[(this->getWidth() * y) + x];
}

const Image::Pixel& Image::at(unsigned int x, unsigned int y) const noexcept {
	assert(this->contains(x, y));

	return this->m_data[(this->getWidth() * y) + x];
}

template<>
void Image::save<Image::Format::PNG>(const std::string& path) {
	stbi_flip_vertically_on_write(true);

	if (
		!stbi_write_png(
			path.c_str(),
			this->getWidth(), this->getHeight(),
			4,
			this->m_data,
			sizeof(Image::Pixel) * this->getWidth()
		)
	) {
		throw std::runtime_error("Failed to write image to file.");
	}
}

Image Image::Create(unsigned int width, unsigned int height, Pixel fill) {
	Pixel* pixels = new Pixel[width * height];

	for (unsigned int i = 0; i < (width * height); i++) {
		pixels[i] = fill;
	}

	return Image(width, height, pixels);
}

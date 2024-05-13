#pragma once

#include <string>

#include <cstdint>

// NOTE(Trevor): Personally, I dislike using private members and
// getters/setters unless actively preventing harm, so we may just
// change this to a struct.

class Image {
public:
	struct Pixel {
		std::uint8_t red;
		std::uint8_t green;
		std::uint8_t blue;
		std::uint8_t alpha;

		static Pixel Black() noexcept;
		static Pixel White() noexcept;

		static Pixel Red() noexcept;
		static Pixel Green() noexcept;
		static Pixel Blue() noexcept;

		static Pixel Magenta() noexcept;

		static Pixel Default() noexcept;
	};

	enum class Format {
		PNG
	};

private:
	unsigned int m_width;
	unsigned int m_height;
	Pixel* m_data;

public:
	Image(unsigned int width, unsigned int height, Pixel* pixels) noexcept;
	Image(const Image& other) = delete;
	Image(Image&& other) = delete;
	~Image() noexcept;

	unsigned int getWidth() const noexcept;
	unsigned int getHeight() const noexcept;

	bool contains(unsigned int x, unsigned int y) const noexcept;

	Pixel& at(unsigned int x, unsigned int y) noexcept;
	const Pixel& at(unsigned int x, unsigned int y) const noexcept;

	template<Format F>
	void save(const std::string& path);

public:
	static Image Create(unsigned int width, unsigned int height, Pixel fill = Pixel::Default());
};

#include <iostream>

#include "types/color.hpp"
#include "types/image.hpp"

int main(int argc, const char* argv[]) {
	(void) argc, (void) argv;

	Image output = Image::Create(512, 512, Image::Pixel::Red());

	for (unsigned int y = 0; y < output.getHeight(); y++) {
		for (unsigned int x = 0; x < output.getWidth(); x++) {
			output.at(x, y) = Image::Pixel::FromColor(
				((x + y) % 2 == 0)
					? Color::Black()
					: Color::Magenta()
			);
		}
	}

	output.save<Image::Format::PNG>("./output.png");

	std::cout << "[DONE]\n";

	return 0;
}

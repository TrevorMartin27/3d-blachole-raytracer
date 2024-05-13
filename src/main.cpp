#include <iostream>

#include "types/image.hpp"

int main(int argc, const char* argv[]) {
	(void) argc, (void) argv;

	Image output = Image::Create(512, 512, Image::Pixel::Red());

	for (unsigned int y = 0; y < output.getHeight(); y++) {
		for (unsigned int x = 0; x < output.getWidth(); x++) {
			output.at(x, y) =
				((x + y) % 2 == 0)
					? Image::Pixel::Black()
					: Image::Pixel::White();
		}
	}

	output.save<Image::Format::PNG>("./output.png");

	return 0;
}

#include "Image.h"

int main(int argc, char** argv) {
	Image test("meme.png");
	test.write("new.png");
	Image copy = test;

	for (int i = 0; i < copy.getWidth() *copy.getHeight(); i++) {
		copy.data[i] = 0;
	}
	copy.write("copy.png");

	Image blanc(100,100,3);
	blanc.write("blanc.jpg");

	return 0;
}
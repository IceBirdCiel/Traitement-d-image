#include "Image.h"
#include "Background.h"
#include <vector>

int main(int argc, char** argv) {

	Image office1("office1.jpg");
	Image office2("office2.jpg");
	Image office3("office3.jpg");
	Image office4("office4.jpg");
	Image office5("office5.jpg");

	std::vector<Image> images;
	images.push_back(office1);
	images.push_back(office2);
	images.push_back(office3);
	images.push_back(office4);
	images.push_back(office5);

	Image background(office1.getWidth(), office2.getHeight(), office3.getChannels());
	Background bg;
	bg.commonBG(images, background);

	return 0;
}
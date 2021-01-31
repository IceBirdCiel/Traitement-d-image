#include "Image.h"
#include "Background.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

	Image scene0("scene0.jpeg");
	Image scene1("scene1.jpeg");
	Image scene2("scene2.jpeg");
	Image scene3("scene3.jpeg");
	Image scene4("scene4.jpeg");
	
	std::vector<Image> images;
	images.push_back(scene0);
	images.push_back(scene1);
	images.push_back(scene2);
	images.push_back(scene3);
	images.push_back(scene4);

	Image background(scene1.getWidth(), scene1.getHeight(), scene1.getChannels());
	Background bg;
	bg.median(images, &background);
	
	background.write("background.jpg");

	return 0;
}
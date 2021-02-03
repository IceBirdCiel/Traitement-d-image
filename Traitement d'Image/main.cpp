#include "Image.h"
#include "Background.h"
#include "Masque.h"
#include "Compose.h"
#include <iostream>
#include <vector>
#include <string>

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

	std::vector<Image> masks;
	for (int i = 0; i < 5; i++) {
		Image mask(images.at(i).getWidth(), images.at(i).getHeight(), images.at(i).getChannels());
		Masque msk;
		msk.maskDetection(background, images.at(i), &mask);

		std::string s = std::to_string(i);
		std::string name = "scene";
		name += s;
		name += ".jpg";
		mask.write(name.c_str());
		masks.push_back(mask);
	}

	Image final(scene1.getWidth(), scene1.getHeight(), scene1.getChannels());
	Compose cp;
	cp.Composition(background, masks, &final);
	final.write("final.jpg");
	
	return 0;
}
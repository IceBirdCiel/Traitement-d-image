#ifndef _BACKGROUND_HPP_
#define _BACKGROUND_HPP_
#include <vector>
#include "Image.h"

class Background {
private:
	std::vector<Image> images;

public:
	void sort(int* tab);
	void median(std::vector<Image> images, Image bg);
	//void commonBG(std::vector<Image> images, Image bg);
};

#endif
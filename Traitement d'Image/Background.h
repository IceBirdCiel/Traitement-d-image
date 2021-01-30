#ifndef _BACKGROUND_HPP_
#define _BACKGROUND_HPP_
#include <vector>
#include "Image.h"

class Background {
private:
	std::vector<Image> images;

public:
	Color majorPixel(std::vector<Image> images, int x, int y);
	void commonBG(std::vector<Image> images, Image bg);
};

#endif
#ifndef _COMPOSE_HPP_
#define _COMPOSE_HPP_
#include "Image.h"
#include <vector>

class Compose {
public:
	void Composition(Image bg, std::vector<Image> listMask, Image *final);
	void fuse(Image *bg, Image mask);
};

#endif

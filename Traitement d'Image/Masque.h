#ifndef _MASQUE_HPP_
#define _MASQUE_HPP_
#include "Image.h"

struct Position {
	int x, y;
};

class Masque {
public:
	void maskDetection(Image bg, Image img, Image* mask);
	void mask_cc(Image* mask);
	int cc_size(Image mask, int x, int y);
};

#endif
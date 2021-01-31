#ifndef _MASQUE_HPP_
#define _MASQUE_HPP_
#include "Image.h"

class Masque {
public:
	void maskDetection(Image bg, Image img, Image* mask);
	void mask_cc(Image* mask);
};

#endif
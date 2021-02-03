#include "Compose.h"
#include <iostream>

void Compose::Composition(Image bg, std::vector<Image> listMask, Image *final) {
	for (int i = 0; i < listMask.size(); i++) {
		fuse(&bg, listMask.at(i));
	}

	for (int x = 0; x < bg.getHeight(); x++) {
		for (int y = 0; y < bg.getWidth(); y++) {
			final->setColor(x, y, bg.getColor(x, y));
		}
	}
}

void Compose::fuse(Image *bg, Image mask) {
	for (int x = 0; x < bg->getHeight(); x++) {
		for (int y = 0; y < bg->getWidth(); y++) {
			int r, g, b;

			r = mask.getColor(x, y).r;
			g = mask.getColor(x, y).g;
			b = mask.getColor(x, y).b;

			if ((r != 0) && (g != 255) && (b != 0)) {
				bg->setColor(x, y, mask.getColor(x,y));
			}
		}
	}
}
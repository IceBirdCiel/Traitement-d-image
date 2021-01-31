#include <vector>
#include "Masque.h"

void Masque::maskDetection(Image bg, Image img, Image* mask) {
	int seuil = 20;

	for (int x = 0; x < img.getHeight(); x++) {
		for (int y = 0; y < img.getWidth(); y++) {
			int r1, g1, b1;
			int r2, g2, b2;

			r1 = bg.getColor(x,y).r;
			g1 = bg.getColor(x,y).g;
			b1 = bg.getColor(x,y).b;
			r2 = img.getColor(x, y).r;
			g2 = img.getColor(x, y).g;
			b2 = img.getColor(x, y).b;

			Color c;

			if (abs(r1-r2) < seuil && abs(g1-g2) < seuil && abs(b1-b2) < seuil) {
				c.r = 0;
				c.g = 255;
				c.b = 0;
				mask->setColor(x, y, c);
			}
			else {
				c.r = 255;
				c.g = 255;
				c.b = 255;
				mask->setColor(x, y, c);
			}
		}
	}
}

void Masque::mask_cc(Image* mask) {

}

int Masque::cc_size(Image mask, int x, int y) {
	std::vector<Position> pos;

	int size = 0;

	Position p;
	p.x = x;
	p.y = y;

	Color black;
	black.r = 0;
	black.g = 0;
	black.b = 0;

	if (mask.getColor(x, y).g == 255) {
		size += 1;
		mask.setColor(x, y, black);
		pos.push_back(p);
	}

	while (!pos.empty()) {
		Position a;
		a = pos.back();
		for (int i = x - 1; i < x + 2; i++) {
			for (int j = y - 1; j < j + 2; j++) {
				if (i < mask.getHeight() && i >= 0 && j < mask.getWidth() && j >= 0) {
					if (mask.getColor(i, j).r == 255 && mask.getColor(i, j).g == 255 && mask.getColor(i, j).b == 255) {
						size += 1;
						mask.setColor(i, j, black);
						Position tmp;
						tmp.x = i;
						tmp.y = j;
						pos.push_back(tmp);
					}
				}
			}
		}
	}

	return size;
}
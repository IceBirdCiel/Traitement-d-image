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
				c.r = r2;
				c.g = g2;
				c.b = b2;
				mask->setColor(x, y, c);
			}
		}
	}
}

void Masque::mask_cc(Image* mask) {

}
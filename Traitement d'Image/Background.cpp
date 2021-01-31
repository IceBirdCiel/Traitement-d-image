#include "Background.h"
#include <iostream>

void Background::sort(int* tab)
{
    int tmp;
    for (int i = 0; i < sizeof(tab); i++) {
        for (int j = 0; j < sizeof(tab) - 1; j++) {
            if (tab[i] > tab[j]) {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }
}

void Background::median(std::vector<Image> images, Image* bg)
{
    int size = images.size();

    int* r = new int[size];
    int* g = new int[size];
    int* b = new int[size];

    for (int x = 0; x < images.at(0).getHeight(); x++) {
        for (int y = 0; y < images.at(0).getWidth(); y++) {
            for (int i = 0; i < size; i++) {
                r[i] = images.at(i).getColor(x, y).r;
                g[i] = images.at(i).getColor(x, y).g;
                b[i] = images.at(i).getColor(x, y).b;
            }
            sort(r);
            sort(g);
            sort(b);

            Color c;
            c.r = r[int(size / 2)];
            c.g = g[int(size / 2)];
            c.b = b[int(size / 2)];
            bg->setColor(x, y, c);
        }
    }
}

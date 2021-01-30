#include "Background.h"

Color Background::majorPixel(std::vector<Image> images, int x, int y)
{
    Color* colors = new Color[images.size()];

    for (int i = 0; i < images.size(); i++) {
        for (int chan = 0; chan < images.at(0).getChannels(); chan++) {
            colors[i] = images.at(i).getColor(x,y);
        }
    }

    int* tab = new int[sizeof(colors)];
    for (int i = 0; i < sizeof(tab); i++) {
        tab[i] = 0;
    }

    for (int i = 0; i < sizeof(colors); i++) {
        for (int j = 1; j < sizeof(colors) - 1; j++) {
            if (colors[i].r == colors[j].r && colors[i].g == colors[j].g && colors[i].b == colors[j].b) {
                tab[i] += 1;
            }
        }
    }

    int max = 0;

    for (int i = 0; i < sizeof(tab); i++) {
        if (tab[max] < tab[i]) max = i;
    }

    return colors[max];
}

void Background::commonBG(std::vector<Image> images, Image bg)
{
    for (int x = 0; x < bg.getWidth(); x++) {
        for (int y = 0; y < bg.getHeight(); y++) {
            for (int chan = 0; chan < bg.getChannels(); chan++) {
                if (chan == 0)
                    bg.data[x * y * chan] = majorPixel(images, x, y).r;
                if (chan == 1)
                    bg.data[x * y * chan] = majorPixel(images, x, y).b;
                if (chan == 2)
                    bg.data[x * y * chan] = majorPixel(images, x, y).g;
            }
        }
    }
}

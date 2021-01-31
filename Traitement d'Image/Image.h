#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_
#include <cstdint>
#include <cstdio>
#include "stb_image.h"
#include "stb_image_write.h"


enum ImageType {
	PNG, JPG, BMP, TGA
};

struct Color {
	int r, g, b;
};

class Image {
private:
	size_t size = 0;
	int width, height, channels;

public:
	uint8_t* data = NULL;

	Image(const char* filename);
	Image(int width, int height, int channels);
	Image(const Image& img);
	~Image();

	bool read(const char* filename);
	bool write(const char* filename);

	ImageType getFileType(const char* filename);

	int getWidth()const;
	int getHeight()const;
	int getChannels()const;

	Color getColor(int x, int y)const;
	void setColor(int x, int y, Color c);
};

#endif
#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include <iostream>
#include <string.h>


Image::Image(const char* filename) {
	if(read(filename)){
		std::cout << "file readed : " << filename << std::endl;
		size = width*height*channels;
	}
	else {
		std::cout << " failed to read image : " << filename << std::endl;
	}
}

Image::Image(int width, int height, int channels) : width(width), height(height), channels(channels) {
	size = width*height*channels;
	data = new uint8_t[size];
}

Image::Image(const Image& img): Image(img.width, img.height, img.channels){
	memcpy(data, img.data, img.size);
}

Image::~Image() {
	stbi_image_free(data);
}

bool Image::read(const char* filename) {
	data = stbi_load(filename, &width, &height, &channels, 0);
	return data != NULL;
}

bool Image::write(const char* filename) {
	ImageType type;
	type = getFileType(filename);
	int succes;
	if (type == PNG) {
		succes = stbi_write_png(filename, width, height, channels, data, width*channels);
	}
	else if (type == JPG) {
		succes = stbi_write_jpg(filename, width, height, channels, data, 100);
	}
	else if (type == BMP) {
		succes = stbi_write_bmp(filename, width, height, channels, data);
	}
	else if (type == TGA) {
		succes = stbi_write_tga(filename, width, height, channels, data);
	}

	return (succes != 0);
}

ImageType Image::getFileType(const char* filename) {
	const char* extension = strrchr(filename, '.');
	if (extension != nullptr) {
		if (strcmp(extension, ".png") == 0) {
			return PNG;
		}
		else if (strcmp(extension, ".jpg") == 0) {
			return JPG;
		}
		else if (strcmp(extension, ".bmp") == 0) {
			return BMP;
		}
		else if (strcmp(extension, ".TGA") == 0) {
			return TGA;
		}
		else {
			return PNG;
		}
	}
	
}

int Image::getWidth()const{
	return width;
}

int Image::getHeight()const{
	return height;
}

int Image::getChannels()const{
	return channels;
}

Color Image::getColor(int x, int y)const
{
	Color c;
	c.r = data[(x * 3 * width) + (y * 3)];
	c.g = data[(x * 3 * width) + (y * 3) + 1];
	c.b = data[(x * 3 * width) + (y * 3) + 2];

	return c;
}

void Image::setColor(int x, int y, Color c) {
	data[(x * 3 * width) + (y * 3)] = c.r;
	data[(x * 3 * width) + (y * 3) + 1] = c.g;
	data[(x * 3 * width) + (y * 3) + 2] = c.b;
}

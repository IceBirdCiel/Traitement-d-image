#include <cstdint>
#include <cstdio>
#include "stb_image.h"
#include "stb_image_write.h"


enum ImageType {
	PNG, JPG, BMP, TGA
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

	int getWidth();
	int getHeight();
	int getChannels();
};
#include "ImageProcessing.h"
unsigned int ImageProcessing::clip(unsigned int x)
{
	if (x < 0)
		return 0;
	if (x > 255)
		return 255;
	return x;
}
void ImageProcessing::process(const Image& src, Image& dst)
{
	dst = src;
}

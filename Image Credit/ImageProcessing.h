#pragma once
#include "Image.h"
class ImageProcessing
{
public:
	unsigned int clip(unsigned int x);
	 void process(const Image& src, Image& dst);
};


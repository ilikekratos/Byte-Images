#pragma once
#include "ImageProcessing.h"
class BrightAndContrast : ImageProcessing
{
private:
	unsigned int gain;
	int bias;
public:
	BrightAndContrast();
	BrightAndContrast(unsigned int a, int b);
	void process(Image& src, Image& dst);
};


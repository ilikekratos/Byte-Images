#pragma once
#include "ImageProcessing.h"
#include <math.h>
class Gamma : ImageProcessing
{
private:
	float factor;
public:
	Gamma();
	Gamma(float factor);
	void process(Image& src, Image& dst);
};


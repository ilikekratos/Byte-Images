#include "BrightAndContrast.h"

BrightAndContrast::BrightAndContrast()
{
	this->gain = 1;
	this->bias = 0;
}
BrightAndContrast::BrightAndContrast(unsigned int a,  int b)
{
	if (a < 0)
		throw std::exception();
	else
	{
		this->gain = a;
		this->bias = b;
	}


}
void BrightAndContrast::process(Image& src, Image& dst)
{
	dst = src;
	for(unsigned int i=0;i< src.getH();i++)
		for (unsigned int j = 0; j < src.getW(); j++)
		{
			dst.at(i,j) = clip((dst.at(i, j) * this->gain) + this->bias);
		}
	
}

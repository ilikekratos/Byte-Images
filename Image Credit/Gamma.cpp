#include "Gamma.h"

Gamma::Gamma()
{
	this->factor = 1;
}
Gamma::Gamma(float factor)
{
	if (factor < 0)
		throw std::exception();
	else
	this->factor = factor;
}
void Gamma::process(Image& src, Image& dst)
{
	dst = src;
	for (unsigned int i = 0; i < src.getH(); i++)
		for (unsigned int j = 0; j < src.getW(); j++)
		{
			if ((pow(dst.at(i,j),factor)> 255))
					dst.at(i, j) = 255;
				else
					dst.at(i, j) = pow(dst.at(i, j), factor);
		}
}

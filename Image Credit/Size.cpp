#include "Size.h"
Size::Size()
{
	this->h = 0;
	this->w = 0;
}
Size::Size(unsigned int width, unsigned int height)
{
	this->h = height;
	this->w = width;
}
void Size::setH(unsigned int height)
{
	this->h = height;
}
void Size::setW(unsigned int width)
{
	this->w = width;
}
unsigned int Size::getW()
{
	return this->w;
}
unsigned int Size::getH()
{
	return this->h;
}
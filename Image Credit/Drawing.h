#pragma once
#include "Image.h"
class Drawing
{
public:
	void drawCircle(Image& img, Point center, int radius, unsigned char color);
	void drawLine(Image& img, Point p1, Point p2,unsigned char color);
	void drawRectangle(Image& img, MyRectangle rec, unsigned char color);
};


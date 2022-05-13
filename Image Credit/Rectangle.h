#pragma once
#include "Point.h"

typedef std::pair<int, int>Pairs;
class MyRectangle
{
private:
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
public:
	MyRectangle();
	MyRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	MyRectangle(Point p1, Point p2);
	unsigned int getX();
	unsigned int getY();
	unsigned int getW();
	unsigned int getH();
	friend std::istream& operator>>(std::istream& in, MyRectangle& rect);
	friend std::ostream& operator<<(std::ostream& os, MyRectangle& rect);
	MyRectangle operator+(Pairs x);
	MyRectangle operator&(MyRectangle obj);
	MyRectangle operator|(MyRectangle obj);
};


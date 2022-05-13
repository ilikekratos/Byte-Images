#pragma once
#include<istream>
class Point
{
private:
	unsigned int x;
	unsigned int y;
public:
	Point();
	Point(unsigned int x, unsigned int y);
	unsigned int getX();
	unsigned int getY();
	void setX(unsigned int x);
	void setY(unsigned int y);
	friend std::ostream& operator<<(std::ostream& os, Point& p);
	friend std::istream& operator>>(std::istream& in, Point& p);
};


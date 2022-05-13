#include "Point.h"
#include <iostream>
Point::Point()
{
	this->x = 0;
	this->y = 0;
}
Point::Point(unsigned int x, unsigned int y)
{
	if (x < 0 || y < 0)
		throw std::exception();
	this->x = x;
	this->y = y;
}
unsigned int Point::getX()
{
	return this->x;
}
unsigned int Point::getY()
{
	return this->y;
}
void Point::setX(unsigned int x)
{
	this->x = x;
}
void Point::setY(unsigned int y)
{
	this->y = y;
}
std::istream& operator>>(std::istream& in, Point& p)
{
	std::cout<< std::endl<<"X:";
	in >> p.x;
	std::cout << std::endl << "Y:";
	in >> p.y;
	return in;

}
std::ostream& operator<<(std::ostream& os, Point& p)
{
	os << "Point of " << p.x << " and " << p.y;
	return os;
}
#include "Rectangle.h"
#include <iostream>
MyRectangle::MyRectangle()
{
	this->x=0;
	this->y=0;
	this->width=0;
	this->height=0;
}
MyRectangle::MyRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
MyRectangle::MyRectangle(Point p1, Point p2)
{
	this->x = p1.getX();
	this->y = p1.getY();
	this->width = p2.getX() - p1.getX();
	this->height = p2.getY() - p1.getY();
}
unsigned int MyRectangle::getX()
{
	return this->x;
}
unsigned int MyRectangle::getY()
{
	return this->y;
}
unsigned int MyRectangle::getW()
{
	return this->width;
}
unsigned int MyRectangle::getH()
{
	return this->height;
}
std::istream& operator>>(std::istream& in, MyRectangle& rect)
{
	std::cout << "X:" << std::endl;
	in >> rect.x;
	std::cout << "Y:" << std::endl;
	in >> rect.y;
	std::cout << "Height:" << std::endl;
	in >> rect.height;
	std::cout << "Width:" << std::endl;
	in >> rect.width;
	return in;
}
std::ostream& operator<<(std::ostream& os, MyRectangle& rect)
{
	os <<"Rectangle:"<<std::endl<< "X:" << rect.x << std::endl << "Y:" << rect.y << std::endl << "Height:" << rect.height << std::endl << "Width:" << rect.width << std::endl;
	return os;
}
MyRectangle MyRectangle::operator+(Pairs x)
{
	this->x += x.first;
	this->width += x.first;
	this->y += x.second;
	this->height += x.second;
	return *this;
}
MyRectangle MyRectangle::operator&(MyRectangle obj)
{
	if (obj.x > this->x + this->width || obj.y > this->y + this->height||obj.y+obj.height<this->y||obj.x+obj.width<this->x)
		throw std::exception();
	else
	{
		if (obj.x > this->x)
		{
			if (obj.x + obj.width < this->x+this->width)
			{
				this->width = obj.width;
			}
			this->x = obj.x;
		}
		if (obj.y > this->y)
		{
			if (obj.y + obj.height < this->y + this->height)
			{
				this->height = obj.height;
			}
			this->y = obj.y;
		}
	}
	return *this;
}
MyRectangle MyRectangle::operator|(MyRectangle obj)
{

	int maxw, maxh;
	if (this->x + this->width > obj.x + obj.width)
		maxw = this->x + this->width;
	else
		maxw = obj.x + obj.width;
	if (this->y - this->height < obj.y - obj.height)
		maxh = this->y + this->height;
	else
		maxh = obj.y - obj.height;
	if (this->x > obj.x)
		this->x = obj.x;
	if (this->y > obj.y)
		this->y = obj.y;
	this->width = maxw-this->x;
	this->height = maxh - this->y;

	return *this;
}
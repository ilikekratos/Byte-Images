#pragma once
#include <string>
#include <windows.h>
#include <exception>
#include <iostream>
#include <string>
#include <fstream>
#include "Point.h"
#include "Size.h"
#include "Rectangle.h"
typedef std::pair<int, int> TValues;

class Image
{
private:
	unsigned char** m_data;
	unsigned int height;
	unsigned int width;
	unsigned int m_gray;
	std::string check;
public:

	Image();
	Image(Size resolution);
	Image(const Image& other);
	~Image();
	unsigned int getW();
	unsigned int getH();
	bool load(std::string imagePath);
	bool save(std::string imagePath);
	Image& operator=(const Image& obj);
	Image operator+(const Image &obj);
	Image operator-(const Image &obj);
	Image operator*(const Image &obj);
	Image operator+(unsigned int value);
	Image operator-(unsigned int value);
	Image operator*(unsigned int value);
	bool isEmpty();
	unsigned char& at(unsigned int x, unsigned int y);
	unsigned char& at(Point pt);
	unsigned char* row(int y);
	void release();
	bool getROI(Image& roiImg, MyRectangle roiRect);
	bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

	friend std::ostream& operator<<(std::ostream& os, Image& imag);

	void drawCircle(Point center, int radius, unsigned char color);
	void drawLine(Point p1, Point p2, unsigned char color);
	void drawRectangle(MyRectangle rec, unsigned char color);
	void drawRectangle(Point p1, Point p2, unsigned char color);

	static Image zeros(unsigned int width, unsigned int height);
	static Image ones(unsigned int width, unsigned int height);
	void histogram(int a[],int binSize);
	void savehisto(std::string imagepath,int binSize);
};


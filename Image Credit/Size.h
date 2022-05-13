#pragma once
class Size
{
private:
	unsigned int w;
	unsigned int h;
public:
	Size();
	Size(unsigned int w, unsigned int h);
	void setW(unsigned int w);
	void setH(unsigned int h);
	unsigned int getW();
	unsigned int getH();
};

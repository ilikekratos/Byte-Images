#pragma once
#include "ImageProcessing.h"
class Convolution : ImageProcessing
{
private:
	unsigned int w;
	unsigned int h;
	 int** ker;
public:
	Convolution();
	void setKer(int& add, int& divide);
	void process(Image&src, Image& dst);
	int calculate(Image& src,int i,int j,float add,float multiply);
	void meanblur(int &add, int& divide);
	void gaussblur(int& add, int& divide);
	void Hsobel(int& add, int& divide);
	void Vsobel(int& add, int& divide);
	void identity(int& add, int& divide);
};


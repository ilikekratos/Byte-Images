#include "TestTime.h"
#include "assert.h"
#include "BrightAndContrast.h"
#include "Gamma.h"
#include "Convolution.h"
void Test()
{
	Image imag1;
	assert(imag1.getH() == 1);
	assert(imag1.getW() == 1);
	Size size1;
	assert(size1.getH() == 0);
	assert(size1.getW() == 0);
	Size size2(1, 1);
	assert(size2.getH() == 1);
	assert(size2.getW() == 1);
	Size size3;
	size3.setH(5);
	size3.setW(5);
	assert(size3.getH() == 5);
	assert(size3.getW() == 5);
	Image imag2(size3);
	assert(imag2.getH() == 5);
	assert(imag2.getW() == 5);
	Image imag3(imag1);
	assert(imag3.getH() == 1);
	assert(imag3.getW() == 1);
	imag1.load("hands.pgm");
	assert(imag1.getH() == 480);
	assert(imag1.getW() == 640);
	imag2.load("gator.pgm");
	//imag3.load("fractal_tree.pgm");
	//imag1.save("handsunited.pgm");
	Image imag4;
	imag4 = imag1;
	imag4.save("hands save.pgm");
	imag4 + imag1;
	imag4.save("almost full 255.pgm");
	imag4 - imag1;
	imag4.save("Should be almost full 255 - hands.pgm");
	imag4 * imag1;
	imag4.save("Definetly 255.pgm");
	imag4 + (-250);
	imag4.save("definetly 5.pgm");
	imag4 - (-5);
	imag4.save("definetly 10.pgm");
	imag4* 10;
	imag4.save("definetly 100.pgm");
	imag4 - 100;
	assert(imag4.isEmpty() == 1);
	imag1.getROI(imag4, 50, 50, 100, 100);
	imag4.save("getroi.pgm");
	MyRectangle rect(50, 50, 100, 100);
	imag1.getROI(imag3, rect);
	imag3.save("getroirec.pgm");
	Point p1(50, 50);
	Point p2(150, 150);
	MyRectangle rect2(p1, p2);
	imag1.getROI(imag3, rect2);
	imag3.save("getroirec2.pgm");
	imag3 = imag1;
	imag3.drawCircle(p1, 30, 0);
	imag3.save("circle.pgm");
	imag3 = imag1;
	imag3.drawLine(p1, p2, 0);
	imag3.save("line.pgm");
	imag3 = imag1;
	imag3.drawRectangle(rect, 0);
	imag3.save("drawrect1.pgm");
	imag3 = imag1;
	imag3.drawRectangle(p1, p2, 0);
	imag3.save("drawrect2.pgm");
	BrightAndContrast proces1(2, 5);
	proces1.process(imag1, imag3);
	imag3.save("brightandcontrast.pgm");
	Gamma proces2(0.7);
	proces2.process(imag1, imag3);
	imag3.save("gamma.pgm");
	std::cout << "Testing convolution now:"<<std::endl;
	int input=0;
	std::cin >> input;
	while (input != -1)
	{
		Convolution proces3;
		proces3.process(imag1, imag3);
		std::cout << "Don't press -1 if u don't want to end convolution testing";
		imag3.save("convolution.pgm");
		std::cin >> input;
	}
	std::cout << imag1;

}

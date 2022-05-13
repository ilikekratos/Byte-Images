// Image Credit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Image.h"
#include "BrightAndContrast.h"
#include "Gamma.h"
#include "Convolution.h"
#include "TestTime.h"
using namespace std;
int main()
{
    Image imag1;
    imag1.load("gator.pgm");
    imag1.savehisto("histogram.pgm",200);
    return 0;

}



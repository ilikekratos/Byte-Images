#include "Convolution.h"
Convolution::Convolution()
{
	this->h = 3;
	this->w = 3;
	this->ker = new  int* [3];
	for (unsigned int i = 0; i < 3; i++)
	{
		this->ker[i] = new  int[3];
	}
	for (unsigned int i = 0; i < 3; i++)
		for (unsigned int j = 0; j < 3; j++)
			this->ker[i][j] = 0;
	this->ker[1][1] = 1;

}
void Convolution::process(Image& src, Image& dst)
{
	dst = src;
	int input;
	int add, divide;
	std::cout <<std::endl<< "Preset or Custom convolution?" << std::endl;
	std::cout << "1 for preset" << std::endl;
	std::cout << "2 for custom" << std::endl;
	std::cin >> input;
	while (!(input == 1 || input == 2))
	{
		std::cout << "Wrong input" << std::endl;
		std::cout << "1 for preset" << std::endl;
		std::cout << "2 for custom" << std::endl;
		std::cin >> input;
	}
	if (input == 1)
	{
		int input2;
		std::cout << "0.Identity" << std::endl;
		std::cout << "1.Mean blur"<<std::endl;
		std::cout << "2.Gauss blur"<<std::endl;
		std::cout << "3.Horizontal sobel" << std::endl;
		std::cout << "4.Vertical sobel" << std::endl;
		std::cin >> input2;
		while (!(input2 == 0 || input2 == 1 || input2 == 2 || input2 == 3 || input2 == 4)) {
			std::cout << "Wrong input" << std::endl;
			std::cin >> input2;
		}
		if (input2 == 0)
			identity(add, divide);
		else
			if (input2 == 1)
				meanblur(add, divide);
			else
				if (input2 == 2)
					gaussblur(add, divide);
				else
					if (input2 == 3)
						Hsobel(add, divide);
					else
						if (input2 == 4)
							Vsobel(add, divide);

	}
	else
	{
		setKer(add, divide);
	}
	for (unsigned int i = this->h / 2 ; i < src.getH() - (this->h / 2); i++)//going in such a way that i cut this->h/2*2 and lines and this->w/2*2 columns
		for (unsigned int j = this->w / 2; j < src.getW() - (this->w / 2); j++)//where h and w are sizes of ker
		{
			dst.at(i, j) = clip(calculate(src,i,j,add,divide));
		}
}

int Convolution::calculate(Image&src,int i,int j,float add,float multiply)
{
	int sum = 0;
	for (unsigned int m = 0; m < this->h; m++)
		for (unsigned n = 0; n < this->w; n++)
			sum += (ker[m][n] * src.at(i+(this->h/2)-m,j+(this->w/2)-n));
	return (sum+add)/multiply;
}
void Convolution::setKer(int& add, int& divide)
{
	std::cout << "Give height of kernel(odd number)" << std::endl;
	std::cin >> this->h;
	while (this->h % 2 == 0) {
		std::cout << "Give again" << std::endl;
		std::cin >> this->h;
	}
	std::cout << "Give width of kernel(odd number)" << std::endl;;
	std::cin >> this->w;
	while (this->w % 2 == 0) {
		std::cout << "Give again" << std::endl;
		std::cin >> this->w;
	}
	std::cout << "What do you add to every convolution?" << std::endl;
	std::cin >> add;
	std::cout << "Then with how much do you divide?" << std::endl;
	std::cin >> divide;
	for (unsigned int i = 0; i < this->h; i++) {
		std::cout << "Line:";
		for (unsigned int j = 0; j < this->w; j++) {
			std::cin >> this->ker[i][j];
		}
		std::cout << std::endl;
	}

}
void Convolution::identity(int& add, int& divide)
{
	add = 0;
	divide = 1;
	this->h = 3;
	this->w = 3;
	for (unsigned int i = 0; i < 3; i++)
		for (unsigned int j = 0; j < 3; j++)
			this->ker[i][j] = 0;
	this->ker[1][1] = 1;
}
void Convolution::meanblur(int& add, int& divide)
{
	add = 0;
	divide = 9;
	this->h = 3;
	this->w = 3;
	this->ker[0][0] =  1;
	this->ker[0][1] = 1;
	this->ker[0][2] = 1;
	this->ker[1][0] = 1;
	this->ker[1][1] =1;
	this->ker[1][2] = 1;
	this->ker[2][0] = 1;
	this->ker[2][1] = 1;
	this->ker[2][2] = 1;
}
void Convolution::gaussblur(int& add, int& divide)
{
	this->h = 3;
	this->w = 3;
	add = 0;
	divide =  16;
	this->ker[0][0] = 1;
	this->ker[0][1] = 2;
	this->ker[0][2] = 1;
	this->ker[1][0] = 2;
	this->ker[1][1] = 4;
	this->ker[1][2] = 2;
	this->ker[2][0] = 1;
	this->ker[2][1] = 2;
	this->ker[2][2] = 1;
}
void Convolution::Hsobel(int& add, int& divide)
{
	this->h = 3;
	this->w = 3;
	add = 4 * 255;
	divide =  8;
	this->ker[0][0] = 1;
	this->ker[0][1] = 2;
	this->ker[0][2] = 1;
	this->ker[1][0] = 0;
	this->ker[1][1] = 0;
	this->ker[1][2] = 0;
	this->ker[2][0] = -1;
	this->ker[2][1] = -2;
	this->ker[2][2] = -1;
}
void Convolution::Vsobel(int& add, int& divide)
{
	this->h = 3;
	this->w = 3;
	add = 4 * 255;
	divide =  8;
	this->ker[0][0] = -1;
	this->ker[0][1] = 0;
	this->ker[0][2] = 1;
	this->ker[1][0] = -2;
	this->ker[1][1] = 0;
	this->ker[1][2] = 2;
	this->ker[2][0] = -3;
	this->ker[2][1] = 0;
	this->ker[2][2] = 3;
}


#include "Image.h"
Image::Image()
{
	this->check = "P2";
	this->m_gray = 0;
	this->width=1;
	this->height=1;
	this->m_data = new unsigned char*[this->height];
	for (unsigned int i = 0; i < this->height; i++)
	{
		this->m_data[i] = new unsigned char[this->width];
	}
	std::cout << "Construction complete"<<std::endl;
}
unsigned int Image::getH()
{
	return this->height;
}
unsigned int Image::getW()
{
	return this->width;
}
Image::Image(Size resolutin)
{
	this->m_gray = 0;
	this->width=resolutin.getW();
	this->height=resolutin.getH();
	this->m_data = new unsigned char*[this->height];
	for (unsigned int i = 0; i < this->height; i++)
	{
		this->m_data[i] = new unsigned char[this->width];
	}
}
Image::Image(const Image& other)
{
	this->check = other.check;
	this->height = other.height;
	this->width = other.width;
	this->m_gray = other.m_gray;;
	this->m_data = new unsigned char* [this->height];
	for (unsigned int i = 0; i < this->height; i++)
	{
		this->m_data[i] = new unsigned char[this->width];
	}
	for (unsigned int i = 0; i < this->height; i++)
		for (unsigned int j = 0; j < this->width; j++)
		{
			this->m_data[i][j] = other.m_data[i][j];
		}
}
Image::~Image() {
	this->release();
	std::cout << "Destruction complete"<<std::endl;
}
bool Image::load(std::string imagePath)
{
	std::ifstream in;
	in.open(imagePath);
	getline(in,this->check);
	if (this->check.compare("P2") != 0)
	{
		std::cout << "Wrong version";
		return false;
	}
	else
		std::cout << "Version Loaded" << std::endl;
	in >> this->width;
	in >> this->height;
	in >> this->m_gray;
	std::cout << "Lengths loaded: " << this->width <<"x"<< this->height <<" Level of gray:"<<this->m_gray<< std::endl;
	this->m_data = new unsigned char* [this->height];
	for (unsigned int i = 0; i < this->height; i++)
	{
		this->m_data[i] = new unsigned char[this->width];
	}
	unsigned int x = 0;
	unsigned int r=0, c=0;
	while (in >> x)
	{
		*(*(this->m_data + r) + c) = x;
		c++;
		if (c== this->width)
		{
			c = 0;
			r++;
		}
	}
	in.close();
	return true;

}
bool Image::save(std::string imagePath)
{
	std::ofstream out;
	out.open(imagePath);
	out <<this->check << std::endl;
	out << this->width << " " << this->height << std::endl;
	out << this->m_gray << std::endl;
	int divide=0;

	for (unsigned int i = 0; i < this->height; i++)
	{
		for (unsigned int j = 0; j < this->width; j++)
		{
			if (int(this->m_data[i][j]) < 100)
			{
				if (int(this->m_data[i][j]) < 10)
					out << "  " << int(this->m_data[i][j]) << " ";
				else
				out <<" "<< int(this->m_data[i][j]) << " ";
			}
			else
			out << int(this->m_data[i][j]) << " ";
			divide++;
			if (divide % 17==0)
				out << std::endl;
		}
	}
	out.close();
	return true;
}
Image& Image::operator=(const Image& obj)
{
	this->height = obj.height;
	this->width = obj.width;
	this->m_gray = obj.m_gray;
	this->m_data = new unsigned char* [this->height];
	for (unsigned int i = 0; i < this->height; i++)
	{
		this->m_data[i] = new unsigned char[this->width];
	}
	for (unsigned int i = 0; i < this->height; i++)
		for (unsigned int j = 0; j < this->width; j++)
		{
			this->m_data[i][j] = unsigned char(obj.m_data[i][j]);
		}
	return *this;
}
Image Image::operator+(const Image &obj)
{
	if (this->height != obj.height || this->width != obj.width)
		throw std::exception();
	else
	{
		for (unsigned int i = 0; i < this->height; i++)
			for (unsigned int j = 0; j < this->width; j++)
			{
				if (this->m_data[i][j] + obj.m_data[i][j] > 255)
					this->m_data[i][j] = 255;
				else
					this->m_data[i][j] = this->m_data[i][j] + obj.m_data[i][j];

			}
		return *this;
	}
}
Image Image::operator-(const Image &obj)
{
	if (this->height != obj.height || this->width != obj.width)
		throw std::exception();
	else
	{
		for (unsigned int i = 0; i < this->height; i++)
			for (unsigned int j = 0; j < this->width; j++)
			{
				if (this->m_data[i][j] - obj.m_data[i][j] < 0)
					this->m_data[i][j] = 0;
				else
					this->m_data[i][j] = this->m_data[i][j] - obj.m_data[i][j];
			}
		return *this;
	}
}
Image Image::operator*(const Image &obj)
{
		if (this->height != obj.height || this->width != obj.width)
			throw std::exception();
		else
		{
			for (unsigned int i = 0; i < this->height; i++)
				for (unsigned int j = 0; j < this->width; j++)
				{
					if (this->m_data[i][j] * obj.m_data[i][j] > 255)
						this->m_data[i][j] = 255;
					else
						this->m_data[i][j] = this->m_data[i][j] * obj.m_data[i][j];
				}
			return *this;
		}
}
Image Image::operator+(unsigned int value)
{
	for (unsigned int i = 0; i < this->height; i++)
		for (unsigned int j = 0; j < this->width; j++)
		{
			if (this->m_data[i][j] + value > 255)
				this->m_data[i][j] = 255;
			else
				this->m_data[i][j] = this->m_data[i][j] +value;
		}
	return *this;
}
Image Image::operator-(unsigned int value)
{
	for (unsigned int i = 0; i < this->height; i++)
		for (unsigned int j = 0; j < this->width; j++)
		{
			if (this->m_data[i][j] - value < 0)
				this->m_data[i][j] = 0;
			else
				this->m_data[i][j] = this->m_data[i][j] - value;
		}
	return *this;
}
Image Image::operator*(unsigned int value)
{
	for (unsigned int i = 0; i < this->height; i++)
		for (unsigned int j = 0; j < this->width; j++)
		{
			if (this->m_data[i][j] * value > 255)
				this->m_data[i][j] = 255;
			else
				this->m_data[i][j] = this->m_data[i][j] * value;
		}
	return *this;
}
bool Image::isEmpty()
{
	for (unsigned int i = 0; i < this->height; i++)
		for (unsigned int j = 0; j < this->width; j++)
		{
			if (this->m_data[i][j] > 0)
				return false;
			
		}
	return true;
}
unsigned char& Image::at(unsigned int x, unsigned int y)
{
	return this->m_data[x][y];
}
unsigned char& Image::at(Point pt)
{
	return this->m_data[pt.getX()][pt.getY()];
}
unsigned char* Image::row(int y)
{
	return *(this->m_data+y);
}
void Image::release()
{
	if (this->m_data != nullptr)
	{
		for (unsigned int i = 0; i < this->height; i++)
			delete[] m_data[i];
		delete[] this->m_data;
		this->m_data = nullptr;
	}
	this->width = 0;
	this->height = 0;
	this->m_gray = 0;
}
bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	if (((y + h) < this->height) && ((x + w) < this->width))
	{
		Image temporary;
		roiImg.height = h;
		roiImg.width = w;
		roiImg.m_gray = this->m_gray;
		temporary.m_data = new unsigned char* [h];
		for (unsigned int i = 0; i < roiImg.height; i++)
		{
			temporary.m_data[i] = new unsigned char[roiImg.width];
		}
		unsigned int m = 0, n = 0;
		for (unsigned int i = y; i < h+y; i++)
		{
			for (unsigned int j = x; j < w+x; j++)
			{
				*(*(temporary.m_data+m)+n) = *(*(this->m_data+i)+j);
				n++;
			}
			m++;
			n = 0;
		}
		roiImg.m_data = new unsigned char* [h];
		for (unsigned int i = 0; i < roiImg.height; i++)
		{
			roiImg.m_data[i] = new unsigned char[roiImg.width];
		}
		for (unsigned int i = 0; i <h ; i++)
			for (unsigned int j = 0; j <w ; j++)
				*(*(roiImg.m_data + i) + j) = *(*(temporary.m_data + i) + j);
		temporary.release();
		return true;
	}
	else
		return false;
}
bool Image::getROI(Image& roiImg, MyRectangle roiRect)
{
	if (((roiRect.getY() + roiRect.getH()) <= this->height) && ((roiRect.getX() + roiRect.getW()) <= this->width))
	{
		Image temporary;
		roiImg.height = roiRect.getH();
		roiImg.width = roiRect.getW();
		roiImg.m_gray = this->m_gray;
		temporary.m_data = new unsigned char* [roiImg.height];
		for (unsigned int i = 0; i < roiImg.height; i++)
		{
			temporary.m_data[i] = new unsigned char[roiImg.width];
		}
		roiImg.m_data = new unsigned char* [roiRect.getH()];
		for (unsigned int i = 0; i < roiImg.height; i++)
		{
			roiImg.m_data[i] = new unsigned char[roiImg.width];
		}
		unsigned int m = 0, n = 0;
		for (unsigned int i = roiRect.getY(); i < roiRect.getH()+roiRect.getY(); i++)
		{
			for (unsigned int j = roiRect.getX(); j < roiRect.getW()+roiRect.getX(); j++)
			{
				*(*(temporary.m_data + m) + n) = *(*(this->m_data + i) + j);
				n++;
			}
			m++;
			n = 0;

		}
		for (unsigned int i = 0; i < roiRect.getH(); i++)
			for (unsigned int j = 0; j < roiRect.getW(); j++)
				*(*(roiImg.m_data + i) + j) = *(*(temporary.m_data + i) + j);
		temporary.release();
		return true;
	}
	else
		return false;
}
std::ostream& operator<<(std::ostream& os, Image& imag) 
{
	
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.dwFontSize.X = 1;
	cfi.dwFontSize.Y = 2;
	wcscpy_s(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 2.1 * imag.width, 3 * imag.height, TRUE);
	
	for (unsigned int i = 0; i < imag.height; i++)
	{
		for (unsigned int j = 0; j < imag.width; j++)
			os << imag.m_data[i][j] << " ";
		os << std::endl;
	}
	return os;
}
void Image::drawCircle( Point center, int radius, unsigned char color)
{
	float x;
	if (center.getX()<=this->width &&center.getY()<= this->height)
	{
		for (unsigned int i = 0; i < this->height; i++)
		{
			for (unsigned int j = 0; j < this->width; j++) {
				x = (j - center.getX()) * (j - center.getX()) + (i - center.getY()) * (i - center.getY()) ;
					if (radius * radius <=x+2*radius&& radius*radius>=x-2*radius)
					{
						this->m_data[i][j] = color;
					}
			}
		}
	}
	else 
		throw std::exception();
}
void Image::drawLine(Point p1, Point p2, unsigned char color)
{
	if (p1.getX() > this->width || p2.getX() > this->width || p1.getY() > this->height || p2.getY() > this->height)
	{
		std::cout << "Uri:" << p1.getX() << " " << p2.getX() << " " << p1.getY() << " " << p2.getY() << " ";
	}
	if (p1.getX() != p2.getX())
	{
		float slope;
		slope = ((p1.getY() - p2.getY()) / (p1.getX() - p2.getX()));
		if (slope < 0)
			slope *= -1;
		float b = p1.getY() - slope * p1.getX();
		for (unsigned int i = 0; i < this->height; i++)
		{
			for (unsigned int j = 0; j < this->width; j++) {
				if (i == j * slope + b && ((i <= p2.getY() && i >= p1.getY()) || (i >= p2.getY() && i <= p1.getY())) && ((j <= p2.getX() && j >= p1.getX()) || (j <= p1.getX() && j >= p2.getX())))
					this->m_data[i][j] = color;
			}

		}
	}
	else
		for (unsigned int i = 0; i < this->height; i++)
		{
			if(((i>=p1.getY()&&i<=p2.getY())||(i<=p1.getY()&&i>=p2.getY())))
				this->m_data[i][p1.getX()] = color;
		}
}
void Image::drawRectangle(MyRectangle rec, unsigned char color)
{
	if (rec.getX() > this->width || rec.getY() > this->height)
	{
		throw std::exception();
	}
	for (unsigned int i = rec.getY(); i <rec.getY()+ rec.getH()&&i<this->height; i++)
	{
		for (unsigned int j = rec.getX(); j <rec.getX()+ rec.getW()&&j<this->width; j++)
			if (j == rec.getX() || j == rec.getW()+rec.getX() - 1||j==this->width-1)
				this->m_data[i][j] = color;
			else
				if (i == rec.getY() || i == rec.getH()+rec.getY() - 1||i==this->height-1)
					this->m_data[i][j] = color;
	}
}
void Image::drawRectangle(Point p1, Point p2, unsigned char color)
{
	if (p2.getX() > this->width || p2.getY() > this->height)
	{
		throw std::exception();
	}
	for (unsigned int i = p1.getY(); i < p2.getY() && i < this->height; i++)
	{
		for (unsigned int j = p1.getX(); j < p2.getX() && j < this->width; j++)
			if (j == p1.getX() || j == p2.getX() - 1 || j == this->width - 1)
				this->m_data[i][j] = color;
			else
				if (i == p1.getY() || i == p2.getY() - 1 || i == this->height - 1)
					this->m_data[i][j] = color;

	}
}
Image Image::zeros(unsigned int width, unsigned int height)
{
	Image zero;
	zero.width = width;
	zero.height = height;
	zero.m_gray = 255;
	zero.m_data = new unsigned char*[height];
	for (unsigned int i = 0; i < height; i++)
	{
		zero.m_data[i] = new unsigned char[width];
	}
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++)
			zero.m_data[i][j] = 0;
	return zero;

}
Image Image::ones(unsigned int width, unsigned int height)
{
	Image one;
	one.width = width;
	one.height = height;
	one.m_gray = 255;
	one.m_data = new unsigned char* [height];
	for (unsigned int i = 0; i < height; i++)
	{
		one.m_data[i] = new unsigned char[width];
	}
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++)
			one.m_data[i][j] = 1;
	return one;
}

void Image::histogram(int a[],int binSize)
{
	for (unsigned int j = 0; j < 255; j++)
	{
		a[j] = 0;
	}
	for (unsigned int i = 0; i < this->height; i++)
	{
		for (unsigned int j = 0; j < this->width; j++)
		{
			a[int(this->m_data[i][j])]++;
		}
	}
	for (unsigned int j = 0; j < 255; j++)
	{
		a[j] /= binSize;
	}
}
void Image::savehisto(std::string imagepath,int binSize)
{
	Image temporary;
	temporary.width = 255;
	temporary.height = this->width * this->height/binSize;
	temporary.m_gray = 255;
	temporary.m_data = new unsigned char* [temporary.height];
	for (unsigned int i = 0; i < temporary.height; i++)
	{
		temporary.m_data[i] = new unsigned char[temporary.width];
	}
	for (unsigned int i = 0; i < temporary.height; i++)
	{
		for (unsigned int j = 0; j < temporary.width; j++)
		{
			temporary.m_data[i][j] = 255;
		}
	}

	Point p1, p2;
	int j = 0;
	p1.setY(temporary.height-1);
	int* a =new int[255];
	this->histogram(a,binSize);
	int max = temporary.height - a[0];
	for (unsigned int i = 0; i < temporary.width; i++)
	{

		p1.setX(i);
		p2.setX(i);
		p2.setY(temporary.height-a[j]);
		if (temporary.height - a[j] < max)
			max = temporary.height - a[j]+1;
		temporary.drawLine(p1, p2, 0);
		j++;
	}
	std::cout << "done";

	std::ofstream out;
	out.open(imagepath);
	out << this->check << std::endl;
	out << temporary.width << " " <<temporary.height- max+1 << std::endl;
	out << this->m_gray << std::endl;
	int divide = 0;

	for (unsigned int i = max-1; i < temporary.height; i++)
	{
		for (unsigned int j = 0; j < temporary.width; j++)
		{
			if (int(temporary.m_data[i][j]) < 100)
			{
				if (int(temporary.m_data[i][j]) < 10)
					out << "  " << int(temporary.m_data[i][j]) << " ";
				else
					out << " " << int(temporary.m_data[i][j]) << " ";
			}
			else
				out << int(temporary.m_data[i][j]) << " ";
			divide++;
			if (divide % 17 == 0)
				out << std::endl;
		}
	}
	out.close();


}
#include "Complex.h"

Complex::Complex(int x, int y):x(x),y(y) {}

Complex::~Complex() {}

int Complex::getX() const { return x;}

int Complex::getY() const { return y;}

std::ostream & operator<<(std::ostream &str, const Complex &c) { return str << std::setw(4)<<c.x << "+ i" <<std::setw(4)<< c.y<<std::endl;}

std::istream & operator >> (std::istream &str, Complex &c)
{
	std::cout << "Enter complex nubmer (x y): ";
	return str >> c.x >> c.y;
}

#pragma once
#include <iostream>
#include <iomanip>
class Complex
{
	int x, y;
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator >> (std::istream&, Complex&);
public:
	Complex(int = 0, int = 0);
	~Complex();
	int getX()const;
	int getY()const;
};


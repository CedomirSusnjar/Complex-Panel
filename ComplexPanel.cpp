#include "ComplexPanel.h"

ComplexPanel::ComplexPanel(int size):size(size),ImageWriter(size,size)
{
	//drawing horizontal & vertical line:
	DrawLine((size-1)/2, 1, (size-1)/2, size-1);
	DrawLine(1, (size-1)/2, size-1, (size-1)/2);
	//drawing '>' on top of horizontal & vertial line:
	DrawLine((size - 1) / 2, 1, (size - 1) / 2 - 10, 11);
	DrawLine((size - 1) / 2, 1, (size - 1) / 2 + 10, 11);
	DrawLine((size - 1), (size - 1) / 2, (size - 1) - 10, (size - 1) / 2 - 10);
	DrawLine((size - 1), (size - 1) / 2, (size - 1) - 10, (size - 1) / 2 + 10);
	//drawing X:
	DrawLine((size - 1) - 15, (size - 1) / 2 + 10, (size - 1) - 10 - 10, (size - 1) / 2 + 10 + 10);
	DrawLine((size - 1) - 20, (size - 1) / 2 + 10, (size - 1) - 10 - 5, (size - 1) / 2 + 10 + 10);
	//drawing iY:
	DrawLine((size - 1) / 2 - 20, 11, (size - 1) / 2 - 25, 16);
	DrawLine((size - 1) / 2 - 30, 11, (size - 1) / 2 - 25, 16);
	DrawLine((size - 1) / 2 - 25, 16, (size - 1) / 2 - 25, 26);
	DrawLine((size - 1) / 2 - 32, 19, (size - 1) / 2 - 32, 26);
	DrawCircle((size - 1) / 2 - 32, 16,2);
	//drawing tick marks:
	for (int i = 10; i < 390; i+=10)
	{
		DrawLine((size - 1) / 2 - 2, i, (size - 1) / 2 + 2, i);
		DrawLine(i, (size - 1) / 2 - 2, i, (size - 1) / 2 + 2);
	}
	//drawing footnote:
	DrawLine((size - 1) - 50, (size - 1) - 40, (size - 1) - 10, (size - 1) - 40);
	DrawLine((size - 1) - 35, (size - 1) - 45, (size - 1) - 35, (size - 1) - 35);
	DrawLine((size - 1) - 25, (size - 1) - 45, (size - 1) - 25, (size - 1) - 35);
	DrawLine((size - 1) - 30, (size - 1) - 65, (size - 1) - 33, (size - 1) - 60);
	DrawLine((size - 1) - 30, (size - 1) - 65, (size - 1) - 30, (size - 1) - 52);
	DrawCircle((size - 1) - 20, (size - 1) - 58,12);
}

void ComplexPanel::markComplex(Complex& c) { DrawCircle(c.getX() + 200, 200 - c.getY(), 4);}

void ComplexPanel::connectComplex(Complex &c1, Complex &c2)
{
	DrawLine(c1.getX() + (size - 1) / 2, (size - 1) / 2 - c1.getY(), c2.getX() + (size - 1) / 2, (size - 1) / 2 - c2.getY());
}

void ComplexPanel::connectNComplex(Complex *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if((i+1)<n)
		connectComplex(arr[i], arr[i + 1]);
	}
	connectComplex(arr[0], arr[i-1]);
}

ComplexPanel::~ComplexPanel() {}
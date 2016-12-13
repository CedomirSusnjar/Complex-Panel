#pragma once
#include "ImageWriter.h"
#include "Complex.h"
class ComplexPanel:public ImageWriter
{
	int size;
public:
	ComplexPanel(int);
	void markComplex(Complex&);
	void connectComplex(Complex&, Complex&);
	void connectNComplex(Complex*,int);
	~ComplexPanel();
};


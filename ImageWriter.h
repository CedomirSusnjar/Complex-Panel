#pragma once
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <string>
#pragma comment(lib,"gdiplus.lib")
using namespace Gdiplus;


class ImageWriter
{
	int GetEncoderClsid(const WCHAR*, CLSID*);
	Gdiplus::Bitmap* bitmap;
	Gdiplus::Graphics* graphics;
	Gdiplus::Pen* blackPen;
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
public:
	ImageWriter(int, int);
	ImageWriter(const ImageWriter&) = delete;
	ImageWriter(ImageWriter&&) = delete;
	ImageWriter& operator=(const ImageWriter&) = delete;
	ImageWriter& operator=(ImageWriter&&) = delete;
	~ImageWriter();
	void DrawCircle(int, int, int);
	void DrawLine(int, int, int, int);
	void SaveImage(const std::wstring&);
};
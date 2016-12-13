#include "ImageWriter.h"
using namespace Gdiplus;
int ImageWriter::GetEncoderClsid(const WCHAR * format, CLSID * pClsid)
{
	UINT num = 0, size = 0;
	ImageCodecInfo* pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;
	GetImageEncoders(num, size, pImageCodecInfo);
	for (UINT j = 0; j < num; ++j)
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;
		}
	free(pImageCodecInfo);
	return -1;
}
ImageWriter::ImageWriter(int width, int height)
{
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	bitmap = new Bitmap(width, height, PixelFormat32bppARGB);
	graphics = new Graphics(bitmap);
	graphics->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);
	blackPen = new Pen(Color::Black);
}
ImageWriter::~ImageWriter()
{
	delete blackPen;
	delete graphics;
	delete bitmap;
	GdiplusShutdown(gdiplusToken);
}
void ImageWriter::DrawCircle(int x, int y, int r)
{
	graphics->DrawEllipse(blackPen, x - r / 2, y - r / 2, r, r);
}
void ImageWriter::DrawLine(int x1, int y1, int x2, int y2)
{
	graphics->DrawLine(blackPen, x1, y1, x2, y2);
}
void ImageWriter::SaveImage(const std::wstring& filename)
{
	CLSID encoderClsid;
	int result = GetEncoderClsid(L"image/png", &encoderClsid);
	bitmap->Save(filename.c_str(), &encoderClsid);
}
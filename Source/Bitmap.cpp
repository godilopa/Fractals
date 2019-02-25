#include <Bitmap.h>
#include <BitmapFileHeader.h>
#include <BitmapInfoHeader.h>

Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new unsigned char[width * height * 3]{0}) {}

Bitmap::~Bitmap() {}

bool Bitmap::Write(string filename)
{
  BitMapHeader fileHeader;
  BitMapInfoHeader infoHeader;

  fileHeader.fileSize = sizeof(fileHeader) + sizeof(infoHeader) + m_width * m_height * 3;
  fileHeader.dataOffset = sizeof(fileHeader) + sizeof(infoHeader);

  infoHeader.width = m_width;
  infoHeader.height = m_height;

  return false;
}

void Bitmap::SetPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
}
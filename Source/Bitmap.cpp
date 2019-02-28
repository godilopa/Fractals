#include <Bitmap.h>
#include <BitmapFileHeader.h>
#include <BitmapInfoHeader.h>

#include <fstream>
#include <iostream>

using namespace std;

Bitmap::Bitmap(int width, int height) : m_pPixels(new unsigned char[width * height * 3])
{
  m_width = width;
  m_height = height;
}

Bitmap::~Bitmap()
{
}

bool Bitmap::Write(string filename)
{
  BitMapHeader fileHeader;
  BitMapInfoHeader infoHeader;

  fileHeader.fileSize = sizeof(BitMapHeader) + sizeof(BitMapInfoHeader) + m_width * m_height * 3;
  fileHeader.dataOffset = sizeof(BitMapHeader) + sizeof(BitMapInfoHeader);

  infoHeader.width = m_width;
  infoHeader.height = m_height;

  fstream file;

  file.open(filename, ios::out | ios::binary);

  if (!file)
    return false;

  file.write((char *)&fileHeader, sizeof(fileHeader));
  file.write((char *)&infoHeader, sizeof(infoHeader));
  file.write((char *)m_pPixels.get(), m_width * m_height * 3);

  file.close();

  if (!file)
    return false;

  return true;
}

void Bitmap::SetPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
  unsigned char *pPixel = m_pPixels.get();
  pPixel += 3 * (y * m_width + x);
  pPixel[0] = b;
  pPixel[1] = g;
  pPixel[2] = r;
}
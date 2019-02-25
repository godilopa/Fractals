#include <Bitmap.h>
#include <BitmapFileHeader.h>
#include <BitmapInfoHeader.h>

#include <fstream>
#include <iostream>

using namespace std;

Bitmap::Bitmap(int width, int height)
{
  m_width = width;
  m_height = height;
  m_pPixels = new unsigned char[width * height * 3];
}

Bitmap::~Bitmap()
{
}

bool Bitmap::Write(string filename)
{
  BitMapHeader fileHeader;
  BitMapInfoHeader infoHeader;

  fileHeader.fileSize = sizeof(fileHeader) + sizeof(infoHeader) + m_width * m_height * 3;
  fileHeader.dataOffset = sizeof(fileHeader) + sizeof(infoHeader);

  infoHeader.width = m_width;
  infoHeader.height = m_height;

  fstream file;

  file.open(filename, ios::out | ios::binary);

  if (!file)
    return false;

  file.write(reinterpret_cast<char *>(&fileHeader), sizeof(fileHeader));
  file.write(reinterpret_cast<char *>(&infoHeader), sizeof(infoHeader));
  file.write(reinterpret_cast<char *>(m_pPixels), m_width * m_height * 3);

  file.close();

  if (!file)
    return false;

  return false;
}

void Bitmap::SetPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
}
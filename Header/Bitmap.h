#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <memory>
using namespace std;

class Bitmap
{
public:
  Bitmap(int width, int height);
  void SetPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
  bool Write(string filename);
  virtual ~Bitmap();

private:
  unique_ptr<unsigned char[]> m_pPixels{nullptr};
  int m_width{0};
  int m_height{0};
};

#endif
#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H

//#include <cstint>;//para hacerlo independiente de la plataforma, asegurar los 32 bits, no incluida en MinGw
#pragma pack(2)

struct BitMapInfoHeader
{
  int headerSize{40};
  int width;
  int height;
  short int planes{1};
  short int bitsPerPixel{24};
  int compression{0};
  int dataSize{0};
  int horizontalResolution{2400};
  int verticalResolution{2400};
  int colors{0};
  int importantColors{0};
};

#endif
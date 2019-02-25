#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

//#include <cstint>;para hacerlo independiente de la plataforma, asegurar los 32 bits, no incluida en MinGw
#pragma pack(2)

struct BitMapHeader
{
  char header[2]{'B', 'M'};
  int fileSize;
  int reserved = 0;
  int dataOffset;
};

#endif
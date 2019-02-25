#ifndef BITMAPHEADER_H
#define BITMAPHEADER_H

//#include <cstint>;para hacerlo independiente de la plataforma, asegurar los 32 bits, no incluida en MinGw
#pragma pack(push, 2)

struct BitMapHeader
{
  char header[2]{'B', 'M'};
  int fileSize;
  int reserved{0};
  int dataOffset;
};

#pragma pack(pop)

#endif
#include <iostream>
#include <Bitmap.h>

#include <fstream>

using namespace std;

int main()
{
  Bitmap bitmap(800, 600);
  bitmap.Write("Prueba.bmp");
  cout << sizeof(short int) << endl;
  return 0;
}
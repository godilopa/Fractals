#include <iostream>
#include <Bitmap.h>

#include <fstream>

using namespace std;

int main()
{
  Bitmap bitmap(100, 200);
  bitmap.Write("Prueba.bmp");
  //cout << "Hello world" << endl;
  return 0;
}
#include <iostream>
#include <Bitmap.h>
#include <Mandelbrot.h>

#include <fstream>

using namespace std;

int main()
{
  int const WIDTH = 800;
  int const HEIGHT = 600;

  Bitmap bitmap(WIDTH, HEIGHT);
  //bitmap.SetPixel(WIDTH * 0.5, HEIGHT * 0.5, 255, 255, 255);
  double max = 999999;
  double min = -999999;

  for (int y = 0; y < HEIGHT; y++)
  {
    for (int x = 0; x < WIDTH; x++)
    { //Pasar a coordenadas -1, 1
      double xFractal = (x - WIDTH / 2) * 2.0 / WIDTH;
      double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

      int iterations = Mandelbrot::GetIteration(xFractal, yFractal);

      unsigned char color = (unsigned char)(256 * (double)iterations / Mandelbrot::MAX_ITERATION);

      bitmap.SetPixel(x, y, color * color, color * color, 0);
      if (color < min)
        min = color;
      if (color > max)
        max = color;
    }
  }

  bitmap.Write("Prueba.bmp");

  return 0;
}
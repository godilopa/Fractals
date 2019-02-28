#include <Mandelbrot.h>
#include <complex>

using namespace std;

Mandelbrot::Mandelbrot() {}
Mandelbrot::~Mandelbrot() {}

int Mandelbrot::GetIteration(double x, double y)
{
  complex<double> z = 0;
  complex<double> c(x, y);

  int iterations = 0;

  while (iterations < MAX_ITERATION)
  {
    z = z * z + c;

    if (abs(z) > 2)
      break;

    iterations++;
  }

  return iterations;
}
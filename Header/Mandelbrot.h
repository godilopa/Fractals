#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot
{
public:
  Mandelbrot();
  virtual ~Mandelbrot();
  static int GetIteration(double x, double y);

public:
  static const int MAX_ITERATION = 1000;

private:
};

#endif
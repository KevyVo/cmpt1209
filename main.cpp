//
//  main.cpp
//  cmpt-1209-group-project
//

/*
 * 1.) Your solution must be implemented in a multifile fashion in such a way that
 * the implementations of all classes are separated from their definitions.
 */
#include <iostream>
#include "Fractal.hpp"

Fractal testMoveConstructor(unsigned int rows, unsigned int cols, char c);

int main(int argc, const char * argv[])
{
    Fractal m1(768U, 1024U, 'm'), j1(768U, 1024U, 'j'), m2, j2;
    saveToPPM(m1, "mandelbrot.ppm");
    saveToPPM(j1, "julia.ppm");
    
    m2 = Fractal(m1);
    j2 = testMoveConstructor(600U, 800U, 'j');

    saveToPPM(j2, "julia_2.ppm");

    return 0;
}

Fractal testMoveConstructor(unsigned int rows, unsigned int cols, char c)
{
    return Fractal(rows, cols, c);
}

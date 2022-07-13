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

    double r_step = 0.0;
    double i_step = 0.0;
    
    for (int i = 0; i < 256; i++)
    {
        Fractal bonus(768U, 1024U, 'b', r_step, i_step);
        saveToPPM(bonus, "bonus-" + to_string(i) + ".ppm");
        
        r_step += 0.0002;
        i_step += -0.0001;
    }

    return 0;
}

/**
 * 13.) You must implement an ordinary function named testMoveConstructor() with
 * the following prototype to construct and return an object of the Fractal class
 *
 * @param rows : number of rows
 * @param cols : number of cols
 * @param c : fractal type
 * @return Fractal : temporary fractal object.
 *
 */
Fractal testMoveConstructor(unsigned int rows, unsigned int cols, char c)
{
    Fractal f(rows, cols, c);
    return f;
}

//
//  Fractal.cpp
//  cmpt-1209-group-project
//
//  Created by Akkarachai Wangcharoensap on 2022-06-23.
//

#include "Fractal.hpp"

Fractal::Fractal() : cols(0), grid(nullptr), maxIter(0), rows(0), type(NULL) {}

/**
 * Copy constructor
 * @param f : fractal object
 */
Fractal::Fractal(const Fractal& f) : cols(f.cols), grid(nullptr), maxIter(f.maxIter), rows(f.rows), type(f.type)
{
    // TODO: Implement deep copy of grid
}

/**
 * Move constructor
 * @param f : r-value fractal object
 */
Fractal::Fractal(Fractal&& f) : cols(f.cols), grid(nullptr), maxIter(f.maxIter), rows(f.rows), type(f.type)
{
    // TODO: Implement move semantics
}

/**
 * Three arguments constructor
 * @param c : number of columns
 * @param r : number of rows
 * @param t : fractal type
 */
Fractal::Fractal(unsigned int c, unsigned int r, char t) : cols(c), grid(nullptr), maxIter(0), rows(r), type(t)
{
    // TODO: Implement grid generation and assignments.
}

/**
 * Determine the pixel color given two complex objects
 * @param c1 : first complex object
 * @param c2 : second complex object
 * @return color : integer value of the color
 */
unsigned int Fractal::determinePixelColor(Complex c1, Complex c2)
{
    // TODO: Implement this function given the requirement.
    return 0;
}

/**
 * Make julia fractal pattern
 */
void Fractal::makeJuliaFractal()
{
    // TODO: Implement this function given the requirement.
}

/**
 * Make mandelbrot fractal pattern
 */
void Fractal::makeMandelbrotFractal()
{
    // TODO: Implement this function given the requirement.
}

/**
 * Overloaded assignment operator
 * @param f : fractal object
 * @return Fractal& : Fractal object
 */
const Fractal& Fractal::operator=(const Fractal& f)
{
    // TODO: Implement overloaded assignment operator
    return (*this);
}

/**
 * Overloaded move assignment operator
 * @param f : fractal object
 * @return Fractal& : Fractal object
 */
Fractal& Fractal::operator=(Fractal&& f)
{
    // TODO: Implement overloaded move assignment operator
    return (*this);
}

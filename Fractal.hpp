//
//  Fractal.hpp
//  cmpt-1209-group-project
//

#ifndef Fractal_hpp
#define Fractal_hpp

#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Pixel.hpp"
#include "Complex.hpp"

/**
 * 8.) You must implement a class named Fractal with the following instance
 * variables and member functions (nothing more, nothing less). Objects of this
 * class represent a Mandelbrot or Julia Fractal pattern.
 */
class Fractal
{
private:
    Pixel** grid;
    
    unsigned int maxIter;
    unsigned int rows;
    unsigned int cols;
    
    char type;
    
    double real_step;
    double imag_step;
    
    unsigned int determinePixelColor(Complex, Complex);
    
    void makeJuliaFractal();
    void makeMandelbrotFractal();
    
    /**
     * Bonus part
     */
    void makeJuliaFractal(double, double);
    void generateMultipleJuliaFractal();
    
    void deallocateGrid();
    void deepCopy(const Fractal&);
    
public:
    
    /**
     * Default constructor
     */
    Fractal();
    
    /**
     * Copy constructor
     */
    Fractal(const Fractal&);
    
    /**
     * Move constructor
     */
    Fractal(Fractal&&);
    
    /**
     * Three arguments constructor
     */
    Fractal(unsigned int, unsigned int, char);
    
    /**
     * Four arguments constructor
     */
    Fractal(unsigned int, unsigned int, char, double, double);
    
    /**
     * Destructor
     */
    ~Fractal();
    
    /**
     * Overloaded assignment operator
     */
    const Fractal& operator=(const Fractal&);
    
    /**
     * Overloaded move assignment operator
     */
    Fractal& operator=(Fractal&&);
    
    friend void saveToPPM(Fractal&, string);
};

Pixel convertToPixel(unsigned int);

#endif /* Fractal_hpp */

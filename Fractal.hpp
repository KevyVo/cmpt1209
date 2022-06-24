//
//  Fractal.hpp
//  cmpt-1209-group-project
//

#ifndef Fractal_hpp
#define Fractal_hpp

#include <stdio.h>

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
    unsigned int cols;
    Pixel** grid;
    unsigned int maxIter;
    unsigned int rows;
    char type;
    
    unsigned int determinePixelColor(Complex, Complex);
    
    void makeJuliaFractal();
    void makeMandelbrotFractal();
    
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
     * Two arguments constructor
     */
    Fractal(unsigned int, unsigned int, char);
    
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
};

#endif /* Fractal_hpp */
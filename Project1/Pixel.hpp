//
//  Pixel.hpp
//  cmpt-1209-group-project
//

#ifndef Pixel_hpp
#define Pixel_hpp

#pragma once
#include <stdio.h>
#include <iostream>

#include <cstring>
#include <math.h>

using namespace std;

/**
 * 5.) You must implement a class named Pixel with the following instance variables
 * and member functions (nothing more, nothing less). Objects of this class
 * represent Pixels in the Fractal pattern images.
 */
class Pixel
{
private:
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    
public:
    
    /**
     * Default constructor
     */
    Pixel();
    
    /**
     * Copy constructor
     */
    Pixel(const Pixel&);
    
    /**
     * Two arguments constructor
     */
    Pixel(unsigned int, unsigned int, unsigned int);
    
    /**
     * Destructor
     */
    ~Pixel();
    
    /**
     * Overloaded offset operator
     */
    unsigned int& operator[](const char*);
    
    /**
     * 7.) You must implement a friend function to overload the insertion operator<<()
     * for the Pixel class. The purpose of this operator is to write the contents of a
     * given Pixel (i.e., the red-green-blue color combination) to an output PPM file.
     */
    friend ostream& operator<<(ostream&, const Pixel&);
};

#endif /* Pixel_hpp */

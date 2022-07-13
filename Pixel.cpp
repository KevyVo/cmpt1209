//
//  Pixel.cpp
//  cmpt-1209-group-project
//

#include "Pixel.hpp"

Pixel::Pixel() : red(0), green(0), blue(0) {}

/**
 * Copy constructor
 * @param p : pixel object
 */
Pixel::Pixel(const Pixel& p) : red(p.red), green(p.green), blue(p.blue) {}

/**
 * Two arguments constructor
 * @param r : red value
 * @param g : green value
 * @param b : blue value
 */
Pixel::Pixel(unsigned int r, unsigned int g, unsigned int b) : red(r), green(g), blue(b) {}

/**
 * Destructor
 */
Pixel::~Pixel() {}

/**
 * 6.) The purpose of the overloaded operator[]() in the Pixel class is to return the
 * values of the red, green, and blue components of a Pixel object. For example,
 * P[“red”] should return the red contribution of Pixel object P. Furthermore, this
 * operator must ensure that the given input argument is valid to the context of the
 * Pixel class. For instance, P[“orange”] is an invalid expression, so your
 * function must gracefully end the application using exit(1).
 *
 * @param c : the character input to be compared.
 * @return double& : value
 */
unsigned int& Pixel::operator[](const char* c)
{
    if (strcmp(c, "red") == 0)
    {
        return this->red;
    }
    else if (strcmp(c, "green") == 0)
    {
        return this->green;
    }
    else if (strcmp(c, "blue") == 0)
    {
        return this->blue;
    }
    
    exit(1);
}

/**
 * Insertion operator
 * write the content of the given pixel to the PPM file.
 *
 * @param p : pixel address
 * @return os : ostream&
 */
ostream& operator<<(ostream& os, const Pixel& p)
{
    os << p.red << " " << p.green << " " << p.blue;
    return os;
}

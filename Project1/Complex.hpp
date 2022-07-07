//
//  Complex.hpp
//  cmpt-1209-group-project
//

/**
 * 2.) You must implement a class named Complex with the following instance
 * variables and member functions (nothing more, nothing less). Objects of this
 * class represent Complex numbers.
 */
#ifndef Complex_hpp
#define Complex_hpp

#pragma once
#include <stdio.h>
#include <iostream>

#include <cstring>
#include <math.h>

class Complex
{
private:
    double imag;
    double real;
    
public:
    
    /**
     * Default constructor
     */
    Complex();
    
    /**
     * Copy constructor
     */
    Complex(const Complex&);
    
    /**
     * Two arguments constructor
     */
    Complex(double, double);
    
    /**
     * Destructor
     */
    ~Complex();
    
    /**
     * Overloaded offset operator
     */
    double& operator[](const char*);
    
    /**
     * 4.) You must implement two friend operators for performing arithmetic addition and
     * multiplication between objects of the Complex class. Furthermore, you must
     * implement a third friend function for calculating the square of the magnitude of
     * a Complex object. The prototypes for these functions are provided below.
     */
    friend const Complex operator*(const Complex&, const Complex&);
    friend const Complex operator+(const Complex&, const Complex&);
    friend double getMagnitudeSquared(const Complex&);
};

#endif /* Complex_hpp */

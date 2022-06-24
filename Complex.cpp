//
//  Complex.cpp
//  cmpt-1209-group-project
//

#include "Complex.hpp"

Complex::Complex() : imag(0.0), real(0.0) {}

/**
 * Copy constructor
 * @param c : complex object
 */
Complex::Complex(const Complex& c) : imag(c.imag), real(c.real) {}

/**
 * Two arguments constructor
 * @param i : imaginary number
 * @param r : real number
 */
Complex::Complex(double i, double r) : imag(i), real(r) {}

/**
 * Destructor
 */
Complex::~Complex() {}

/**
 * 3.) The purpose of the overloaded operator[]() in the Complex class is mutate (or
 * set) the values of the real and imaginary parts of a Complex object. For example,
 * Z[“real”] = 0.0; should change the real part of Complex object Z to 0.0.
 * Furthermore, this operator must ensure that the given input argument is valid to
 * the context of the Complex class. For instance, Z[“unreal”] is an invalid
 * expression, so your function must gracefully end the application using exit(1).
 *
 * @param c : the character input to be compared.
 * @return double& : value
 */
double& Complex::operator[](const char* c)
{
    if (strcmp(c, "real") == 0)
    {
        return this->real;
    }
    else if (strcmp(c, "imag") == 0)
    {
        return this->imag;
    }
    
    exit(1);
}

/**
 * @param c1 : first complex object
 * @param c2 : second complex object
 * @return Complex : new complex object
 */
const Complex operator*(const Complex& c1, const Complex& c2)
{
    return Complex(c1.imag * c2.imag, c1.real * c2.real);
}

/**
 * @param c1 : first complex object
 * @param c2 : second complex object
 * @return Complex : new complex object
 */
const Complex operator+(const Complex& c1, const Complex& c2)
{
    return Complex(c1.imag + c2.imag, c1.real + c2.real);
}

/**
 * @param c : complex object
 * @return double : magnitude
 */
double getMagnitudeSquared(const Complex& c)
{
    return sqrt(pow(c.imag, 2) + pow(c.real, 2));
}

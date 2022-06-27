//
//  Fractal.cpp
//  cmpt-1209-group-project
//

#include "Fractal.hpp"

Fractal::Fractal() : rows(0), cols(0), grid(nullptr), maxIter(0), type(NULL)
{
    cout << "> Default constructor called..." << endl;
}

/**
 * Copy constructor
 * @param f : fractal object
 */
Fractal::Fractal(const Fractal& f) : rows(f.rows), cols(f.cols), grid(nullptr), maxIter(f.maxIter), type(f.type)
{
    cout << "> Copy constructor called..." << endl;
    
    // Deep copy
    this->deepCopy(f);
    
    if (f.type == 'm')
    {
        this->makeMandelbrotFractal();
    }
    else if (f.type == 'j')
    {
        this->makeJuliaFractal();
    }
    else {
        throw "Unknown fractual type is given.";
    }
}

/**
 * Move constructor
 * @param f : r-value fractal object
 */
Fractal::Fractal(Fractal&& f) : rows(f.rows), cols(f.cols), grid(nullptr), maxIter(0), type(0)
{
    cout << "> Move constructor called..." << endl;
    
    // Steal f object resources. OR: (move f object resources to the calling object)
    this->grid = f.grid;
    this->maxIter = f.maxIter;
    this->rows = f.rows;
    this->cols = f.cols;
    this->type = f.type;

    f.grid = nullptr;
}

/**
 * Three arguments constructor
 * @param r : number of rows
 * @param c : number of columns
 * @param t : fractal type
 */
Fractal::Fractal(unsigned int r, unsigned int c, char t) : rows(r), cols(c), grid(nullptr), maxIter(0), type(t)
{
    cout << "> 3-arg constructor called..." << endl;
    
    // Initialize grid rows
    this->grid = new Pixel*[r];
    for (unsigned int i = 0; i < r; i++)
    {
        // Initialize grid columns
        this->grid[i] = new Pixel[c];
        
        for (unsigned int n = 0; n < c; n++)
        {
            // Instantiate the Pixel object at ith row and nth column position.
            this->grid[i][n] = Pixel();
        }
    }
    
    if (t == 'm')
    {
        this->makeMandelbrotFractal();
    }
    else if (t == 'j')
    {
        this->makeJuliaFractal();
    }
    else {
        throw "Unknown fractual type is given.";
    }
}

Fractal::~Fractal()
{
    cout << "> Destructor called ..." << endl;
    this->deallocateGrid();
}

/**
 * Deallocate grid dynamic memory
 */
void Fractal::deallocateGrid()
{
    
    if (this->grid != nullptr)
    {
        for (unsigned int i = 0; i < this->rows; i++)
        {
            delete[] this->grid[i];
            this->grid[i] = nullptr;
        }
    }
    
    delete[] this->grid;
    this->grid = nullptr;
}

/**
 * Deep copy
 * @param f : fractal object
 */
void Fractal::deepCopy(const Fractal& f)
{
    this->rows = f.rows;
    this->cols = f.cols;
    this->maxIter = f.maxIter;
    this->type = f.type;
    
    // Initialize grid rows
    this->grid = new Pixel*[f.rows];
    for (unsigned int i = 0; i < f.rows; i++)
    {
        // Initialize grid columns
        this->grid[i] = new Pixel[f.cols];
        for (unsigned int n = 0; n < f.cols; n++)
        {
            // Assign each grid to the same grid as the given fractal object. (Deep copy)
            this->grid[i][n] = Pixel(
                 f.grid[i][n]["red"],
                 f.grid[i][n]["green"],
                 f.grid[i][n]["blue"]
            );
        }
    }
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
 * Make Julia fractal pattern
 */
void Fractal::makeJuliaFractal()
{
    // TODO: Implement this function given the requirement.
    cout << "> Now creating the Julia patterns..." << endl;
}

/**
 * Make Mandelbrot fractal pattern
 */
void Fractal::makeMandelbrotFractal()
{
    // TODO: Implement this function given the requirement.
    cout << "> Now creating the Mandelbrot patterns..." << endl;
}

/**
 * Overloaded assignment operator
 * @param f : fractal object
 * @return Fractal& : Fractal object
 */
const Fractal& Fractal::operator=(const Fractal& f)
{
    if (this != &f)
    {
        this->rows = f.rows;
        this->cols = f.cols;
        this->maxIter = f.maxIter;
        this->type = f.type;

        if (this->grid != nullptr)
        {
            this->deallocateGrid();
        }
        
        // Deep copy
        this->deepCopy(f);
    }
    
    return (*this);
}

/**
 * Overloaded move assignment operator
 * @param f : fractal object
 * @return Fractal& : Fractal object
 */
Fractal& Fractal::operator=(Fractal&& f)
{
    cout << "> Move assignment operator called..." << endl;
    
    if (this != &f)
    {
        swap(this->grid, f.grid);
        swap(this->rows, f.rows);
        swap(this->cols, f.cols);
        swap(this->maxIter, f.maxIter);
        swap(this->type, f.type);
    }
    
    return (*this);
}

/**
 * Write Fractal to a PPM file.
 *
 * @param f : fractal object
 * @param name : name of the output file.
 */
void saveToPPM(Fractal& f, string name)
{
    // TODO: Implement this function given the requirement.
    cout << "> Saving Fractal object to ASCII file..." << endl;
}

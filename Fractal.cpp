//
//  Fractal.cpp
//  cmpt-1209-group-project
//

#include "Fractal.hpp"

Fractal::Fractal() : rows(0), cols(0), grid(nullptr), maxIter(512), type(NULL)
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
    // b as in bonus.
    else if (f.type == 'b')
    {
        this->makeJuliaFractal(-0.1, 0.1);
    }
    else {
        throw "Unknown fractual type is given.";
    }
}

/**
 * Move constructor
 * @param f : r-value fractal object
 */
Fractal::Fractal(Fractal&& f) : rows(f.rows), cols(f.cols), grid(nullptr), maxIter(512), type(NULL)
{
    cout << "> Move constructor called..." << endl;
    
    // Steal f object resources. OR: (move f object resources to the calling object)
    this->grid = f.grid;
    this->maxIter = f.maxIter;
    this->rows = f.rows;
    this->cols = f.cols;
    this->type = f.type;

    f.grid = nullptr;
    f.rows = 0;
    f.cols = 0;
    f.type = NULL;
    f.maxIter = 0;
}

/**
 * Three arguments constructor
 * @param r : number of rows
 * @param c : number of columns
 * @param t : fractal type
 */
Fractal::Fractal(unsigned int r, unsigned int c, char t) : rows(r), cols(c), grid(nullptr), maxIter(512), type(t)
{
    cout << "> 3-arg constructor called..." << endl;
    
    // Initialize grid rows
    this->grid = new Pixel*[r];
    for (unsigned int i = 0; i < r; i++)
    {
        // Initialize grid columns
        this->grid[i] = new Pixel[c];

    }
    
    if (t == 'm')
    {
        this->makeMandelbrotFractal();
    }
    else if (t == 'j')
    {
        this->makeJuliaFractal();
    }
    else if (t == 'b')
    {
        this->makeJuliaFractal(this->real_step, this->imag_step);
    }
    else {
        throw "Unknown fractual type is given.";
    }
}

/**
 * Five arguments constructor
 * @param r : number of rows
 * @param c : number of columns
 * @param t : fractal type
 * @param r_s : real step
 * @param i_s : imaginary step
 */
Fractal::Fractal(unsigned int r, unsigned int c, char t, double r_s, double i_s) : rows(r), cols(c), grid(nullptr), maxIter(512), type(t), real_step(r_s), imag_step(i_s)
{
    cout << "> 3-arg constructor called..." << endl;
    
    // Initialize grid rows
    this->grid = new Pixel*[r];
    for (unsigned int i = 0; i < r; i++)
    {
        // Initialize grid columns
        this->grid[i] = new Pixel[c];
    }
    
    if (t == 'm')
    {
        this->makeMandelbrotFractal();
    }
    else if (t == 'j')
    {
        this->makeJuliaFractal();
    }
    else if (t == 'b')
    {
        this->makeJuliaFractal(this->real_step, this->imag_step);
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
 * @param z : first complex object
 * @param c : second complex object
 * @return color : integer value of the color
 */
unsigned int Fractal::determinePixelColor(Complex z, Complex c)
{
    double lengthSquared;
    unsigned int iter = 0;
    
    while (iter < this->maxIter)
    {
        iter = iter + 1;
        z = z * z;
        z = z + c;
        lengthSquared = getMagnitudeSquared(z);
        
        if (lengthSquared > 4.0)
        {
            return iter;
        }
    }
    
    return this->maxIter;
}

/**
 * Make Julia fractal pattern
 */
void Fractal::makeJuliaFractal()
{
    cout << "> Now creating the Julia patterns..." << endl;

    Complex Z, C;

    double step_height = 4.0 / (double)this->rows;
    double step_width = 4.0 / (double)this->cols;
    
    C["real"] = -0.8;
    C["imag"] = 0.156;
    
    for (unsigned int j = 0; j < this->rows; j++)
    {
        for (unsigned int k = 0; k < this->cols; k++)
        {
            Z["imag"] = ((double)j * step_height) - 2.0;
            Z["real"] = ((double)k * step_width) - 2.0;
            
            unsigned int Color = this->determinePixelColor(Z, C);
            this->grid[j][k] = convertToPixel(Color);
        }
    }
}

/**
 * Make dynamic julia fractal pattern given the factor and step
 */
void Fractal::makeJuliaFractal(double r_step, double i_step)
{
    this->real_step = r_step;
    this->imag_step = i_step;
    
    cout << "> Bonus: Now creating dynamic Julia patterns..." << endl;

    Complex Z, C;

    double step_height = 4.0 / (double)this->rows;
    double step_width = 4.0 / (double)this->cols;
    
    C["real"] = -0.8;
    C["imag"] = 0.156;
    
    for (unsigned int j = 0; j < this->rows; j++)
    {
        for (unsigned int k = 0; k < this->cols; k++)
        {
            Z["imag"] = ((double)j * step_height) - 2.0;
            Z["real"] = ((double)k * step_width) - 2.0;
        
            Z["real"] *= this->real_step;
            Z["imag"] *= this->imag_step;
            
            unsigned int Color = this->determinePixelColor(Z, C);
            this->grid[j][k] = convertToPixel(Color);
        }
    }
}

/**
 * Make Mandelbrot fractal pattern
 */
void Fractal::makeMandelbrotFractal()
{
    cout << "> Now creating the Mandelbrot patterns..." << endl;

    Complex Z, C;
    
    double step_height = 4.0 / (double) this->rows;
    double step_width = 4.0 / (double) this->cols;
    
    for (unsigned int j = 0; j < this->rows; j++)
    {
        for (unsigned int k = 0; k < this->cols; k++)
        {
            Z["imag"] = 0.0;
            Z["real"] = 0.0;
            C["real"] = ((double)j * step_height) - 2.0;
            C["imag"] = ((double)k * step_width) - 2.0;

            unsigned int Color = this->determinePixelColor(Z, C);
            this->grid[j][k] = convertToPixel(Color);
        }
    }
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
    ofstream outFile;

    outFile.open(name, ios::out | ios::binary);

    if (!outFile) {
        cout << "File : " << name << " cannot be created." << endl;
    }

    cout << "> Saving Fractal object to ASCII file..." << endl;

    outFile << "P3" << endl;
    outFile << "# some comment here" << endl;
    outFile << f.cols << " " << f.rows << endl;
    outFile << 7 << endl;

    for (unsigned int i = 0; i < f.rows; i++)
    {
        for (unsigned int j = 0; j < f.cols; j++)
        {
            outFile << f.grid[i][j] << " ";
        }
        
        outFile << endl;
    }

    outFile.close();
}

/**
 * Create a Pixel object given the color value.
 * @param color : raw color value.
 * @return Pixel : new pixel
 */
Pixel convertToPixel(unsigned int color)
{
    unsigned int red = (color / 64) % 8;
    unsigned int green = (color / 8) % 8;
    unsigned int blue = color % 8;

    return Pixel(red, green, blue);
}

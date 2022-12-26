#include "LibraryCode.hpp"

#include <math.h>

double mySqrt(double input)
{
    if(input < 0)
    {
        throw std::runtime_error("Negative argiment");
    }
    return sqrt(input);
}
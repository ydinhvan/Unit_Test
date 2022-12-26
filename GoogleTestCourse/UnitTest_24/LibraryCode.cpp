#include "LibraryCode.hpp"

void toUpper(char *inputString)
{
    for(unsigned i = 0; i < strlen(inputString); i++)
    {
        inputString[i] = toupper(inputString[i]);
    }
}
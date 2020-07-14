/**//* 35.588.676-RIOS,MarcosAdrian-(01-2964) *//**/

#ifndef FIGURA_H_
#define FIGURA_H_

#include "FiguraInvalidaException.h"

class Figura
{
public:
    virtual ~Figura(){};
    virtual double area() const = 0;
};


#endif // FIGURA_H_

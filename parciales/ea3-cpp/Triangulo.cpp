/**//* 35.588.676-RIOS,MarcosAdrian-(01-2964) *//**/

#include "Triangulo.h"
#include "FiguraInvalidaException.h"

Triangulo::Triangulo(double _base, double _altura) : base(_base), altura(_altura) {
    if(_base <= 0 || _altura <= 0){
        throw FiguraInvalidaException();
    }
}

double Triangulo::area() const
{
    return (this->base * this->altura) / 2;
}

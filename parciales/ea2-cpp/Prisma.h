/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 35.588.676-RIOS,MarcosAdrian-(01-2964) *//**/
/**//**   DEBE MODIFICAR LA L�NEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**         COMPLETE LA DECLARACI�N DE LA CLASE          **//**//**//**/

#ifndef PRISMA_H_
#define PRISMA_H_

#include <iostream>
#include <string>

using namespace std;

class Prisma
{
private:
    int alto;
    int ancho;
    int profundidad;
    string color;

public:
    Prisma(const string& color = "Incoloro", int alto = 1, int ancho = 1, int profundidad = 1);


    Prisma operator ++(int);
    Prisma& operator --();
    friend Prisma operator *(int mult, const Prisma& p);
    friend ostream& operator <<(ostream& sal, const Prisma& p);
};

#endif // PRISMA_H_

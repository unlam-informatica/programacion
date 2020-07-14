
#include "main.h"

int main()
{
    cout << "Hello world!" << endl;

    Prisma pri0; // 1 x 1 x 1
    Prisma pri1("Azul", -10, -2); // 3 x 2 x 1
    Prisma pri2("Verde", 8, 8, 8); // 8 x 8 x 8
    Prisma pri3(pri0); // 1 x 1 x 1

    cout << endl << "Valores inicales" << endl;
    cout << "esperado 1x1x1-Incoloro - pri0:" << pri0 << endl;
    cout << "esperado 3x2x1-Azul - pri1:" << pri1 << endl;
    cout << "esperado 8x8x8-Verde - pri2:" << pri2 << endl;
    cout << "esperado 1x1x1-Incoloro - pri3:" << pri3 << endl;

    pri3 = 5 * pri1;
    pri1++;
    --pri2;

    cout << endl << "Valores finales" << endl;
    cout << "esperado 1x1x1-Incoloro - pri0:" << pri0 << endl;
    cout << "esperado 4x3x2-Azul - pri1:" << pri1 << endl;
    cout << "esperado 7x7x7-Verde - pri2:" << pri2 << endl;
    cout << "esperado 15x10x5-Azul - pri3:" << pri3 << endl;

    return 0;
}


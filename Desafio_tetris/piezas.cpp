#include "piezas.h"

void limpiar_Forma(unsigned char forma[4])
{
    for(int i = 0; i < 4; i++)
        forma[i] = 0;
}

void generar_Pieza(unsigned char forma[4], int tipo, int rotacion)
{
    limpiar_Forma(forma);

    switch(tipo)
    {
    case 0: // I
        if(rotacion % 2 == 0)
            forma[0] = 0b11110000;
        else
        {
            forma[0] = 0b10000000;
            forma[1] = 0b10000000;
            forma[2] = 0b10000000;
            forma[3] = 0b10000000;
        }
        break;

    case 1: // O
        forma[0] = 0b11000000;
        forma[1] = 0b11000000;
        break;

    }
}

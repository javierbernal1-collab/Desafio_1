#include "movimiento.h"
#include "Tablero.h"

bool mover_Izquierda(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int &filaPieza, int &columnaPieza)
{
    int nuevaColumna = columnaPieza - 1;

    if(posicion_Valida(tablero, alto, ancho, forma, filaPieza, nuevaColumna))
    {
        columnaPieza = nuevaColumna;
        return true;
    }

    return false;
}

bool mover_Derecha(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int &filaPieza, int &columnaPieza)
{
    int nuevaColumna = columnaPieza + 1;

    if(posicion_Valida(tablero, alto, ancho,
                        forma, filaPieza, nuevaColumna))
    {
        columnaPieza = nuevaColumna;
        return true;
    }

    return false;
}

bool mover_Abajo(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int &filaPieza, int &columnaPieza)
{
    int nuevaFila = filaPieza + 1;

    if(posicion_Valida(tablero, alto, ancho, forma, nuevaFila, columnaPieza))
    {
        filaPieza = nuevaFila;
        return true;
    }

    return false;
}

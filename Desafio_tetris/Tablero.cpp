#include <iostream>
#include "tablero.h"

using namespace std;

void crear_Tablero(unsigned char** &tablero, int alto, int ancho)
{
    int bytesPorFila = ancho / 8;

    tablero = new unsigned char*[alto];

    for(int i = 0; i < alto; i++)
        tablero[i] = new unsigned char[bytesPorFila];
}

void inicializar_Tablero(unsigned char** tablero, int alto, int bytesPorFila)
{
    for(int i = 0; i < alto; i++)
        for(int j = 0; j < bytesPorFila; j++)
            tablero[i][j] = 0;
}

bool posicion_Valida(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int filaPieza, int columnaPieza)
{
    (void) ancho;
    for(int i = 0; i < 4; i++)
    {
        if(forma[i] == 0)
            continue;

        int filaTablero = filaPieza + i;

        if(filaTablero < 0 || filaTablero >= alto)
            return false;

        for(int bit = 7; bit >= 0; bit--)
        {
            if(forma[i] & (1 << bit))
            {
                int bitFinal = bit - columnaPieza;

                if(bitFinal < 0 || bitFinal > 7)
                    return false;

                if(tablero[filaTablero][0] & (1 << bitFinal))
                    return false;
            }
        }
    }

    return true;
}

void imprimir_Tablero(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int filaPieza, int columnaPieza)
{
    int bytesPorFila = ancho / 8;

    for(int i = 0; i < alto; i++)
    {
        cout << "|";

        for(int j = 0; j < bytesPorFila; j++)
        {
            for(int bit = 7; bit >= 0; bit--)
            {
                bool ocupado = false;


                if(tablero[i][j] & (1 << bit))
                    ocupado = true;


                int filaRelativa = i - filaPieza;

                if(filaRelativa >= 0 && filaRelativa < 4)
                {
                    int bitPieza = bit + columnaPieza;

                    if(bitPieza >= 0 && bitPieza < 8)
                        if(forma[filaRelativa] & (1 << bitPieza))
                            ocupado = true;
                }

                if(ocupado)
                    cout << "#";
                else
                    cout << ".";
            }
        }

        cout << "|" << endl;
    }


    cout << " ";
    for(int i = 0; i < ancho; i++)
        cout << "--";
    cout << endl;

}

void liberar_Tablero(unsigned char** tablero, int alto)
{
    for(int i = 0; i < alto; i++)
        delete[] tablero[i];

    delete[] tablero;
}
void fijar_Pieza(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int filaPieza, int columnaPieza)
{
    int bytesPorFila = ancho / 8;

    for(int i = 0; i < 4; i++)
    {
        if(forma[i] == 0)
            continue;

        int filaTablero = filaPieza + i;

        if(filaTablero >= 0 && filaTablero < alto)
        {
            unsigned char piezaDesplazada =
                forma[i] >> columnaPieza;

            for(int j = 0; j < bytesPorFila; j++)
            {
                tablero[filaTablero][j] |= piezaDesplazada;
            }
        }
    }
}


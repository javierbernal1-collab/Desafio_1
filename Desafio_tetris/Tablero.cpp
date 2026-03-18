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

void imprimir_Tablero(unsigned char** tablero,
                      int alto,
                      int ancho,
                      unsigned char forma[4],
                      int filaPieza,
                      int columnaPieza)
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
                    int bitPieza = bit - columnaPieza;

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

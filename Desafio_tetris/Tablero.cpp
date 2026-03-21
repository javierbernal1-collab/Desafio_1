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

bool posicion_Valida(unsigned char** tablero,
                     int alto,
                     int ancho,
                     unsigned char forma[4],
                     int filaPieza,
                     int columnaPieza)
{

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
                int columnaGlobal =
                    (7 - bit) + columnaPieza;

                if(columnaGlobal < 0 ||
                    columnaGlobal >= ancho)
                    return false;

                int byteIndex =
                    columnaGlobal / 8;

                int bitIndex =
                    7 - (columnaGlobal % 8);

                if(tablero[filaTablero][byteIndex] &
                    (1 << bitIndex))
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

        for(int col = 0; col < ancho; col++)
        {
            bool ocupado = false;

            int byteIndex = col / 8;
            int bitIndex  = 7 - (col % 8);


            if(tablero[i][byteIndex] & (1 << bitIndex))
                ocupado = true;


            int filaRelativa = i - filaPieza;

            if(filaRelativa >= 0 && filaRelativa < 4)
            {
                for(int bit = 7; bit >= 0; bit--)
                {
                    if(forma[filaRelativa] & (1 << bit))
                    {
                        int columnaGlobal =
                            (7 - bit) + columnaPieza;

                        if(columnaGlobal == col)
                            ocupado = true;
                    }
                }
            }

                if(ocupado)
                    cout << "#";
                else
                    cout << ".";
        }

        cout << "|" << endl;
    }
        cout << " ";
        for(int i = 0; i < ancho * 2; i++)
            cout << "-";
        cout << endl;

        cout << "Accion: [A]Izq [D]Der [S]Bajar [W]Rotar [Q]Salir\n";

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

void fijar_Pieza(unsigned char** tablero,
                 int alto,
                 int ancho,
                 unsigned char forma[4],
                 int filaPieza,
                 int columnaPieza)
{

    for(int i = 0; i < 4; i++)
    {
        if(forma[i] == 0)
            continue;

        int filaTablero = filaPieza + i;

        if(filaTablero >= 0 && filaTablero < alto)
        {
            for(int bit = 7; bit >= 0; bit--)
            {
                if(forma[i] & (1 << bit))
                {
                    int columnaGlobal =
                        (7 - bit) + columnaPieza;

                    if(columnaGlobal >= 0 &&
                        columnaGlobal < ancho)
                    {
                        int byteIndex =
                            columnaGlobal / 8;

                        int bitIndex =
                            7 - (columnaGlobal % 8);

                        tablero[filaTablero][byteIndex] |=
                            (1 << bitIndex);
                    }
                }
            }
        }
    }
}
void eliminar_Filas_Completas(unsigned char** tablero,
                              int alto,
                              int ancho)
{
    int bytesPorFila = ancho / 8;

    for(int i = 0; i < alto; i++)
    {
        bool completa = true;

        for(int j = 0; j < bytesPorFila; j++)
        {
            if(tablero[i][j] != 255)
            {
                completa = false;
                break;
            }
        }

        if(completa)
        {
            for(int k = i; k > 0; k--)
            {
                for(int j = 0; j < bytesPorFila; j++)
                    tablero[k][j] = tablero[k-1][j];
            }

            for(int j = 0; j < bytesPorFila; j++)
                tablero[0][j] = 0;
        }
    }
}

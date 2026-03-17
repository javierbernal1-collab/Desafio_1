#include <iostream>
using namespace std;

void crear_Tablero(unsigned char** &tablero, int alto, int ancho)
{
    int bytes = ancho / 8;

    tablero = new unsigned char*[alto];

    for (int i = 0; i < alto; i++)
    {
        tablero[i] = new unsigned char[bytes];
    }
}
void inicializar_Tablero(unsigned char** tablero, int alto, int bytesPorFila)
{
    for (int i = 0; i < alto; i++)
    {
        for (int j = 0; j < bytesPorFila; j++)
        {
            tablero[i][j] = 0;
        }
    }
}



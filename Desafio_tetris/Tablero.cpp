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
void imprimir_Tablero(unsigned char** tablero, int alto, int ancho)
{
    int bytesPorFila = ancho / 8;

    for (int i = 0; i < alto; i++)
    {
        for (int j = 0; j < bytesPorFila; j++)
        {
            for (int bit = 7; bit >= 0; bit--)
            {
                if (tablero[i][j] & (1 << bit))
                    cout << "#";
                else
                    cout << ".";
            }
        }
        cout << endl;
    }
}
void liberar_Tablero(unsigned char** tablero, int alto)
{
    for (int i = 0; i < alto; i++)
    {
        delete[] tablero[i];
    }

    delete[] tablero;
}


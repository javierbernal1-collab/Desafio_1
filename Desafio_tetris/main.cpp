#include <iostream>
#include "tablero.h"
#include "piezas.h"

using namespace std;

int main()
{
    int ancho, alto;

    cout << "Ingrese ancho (multiplo de 8, minimo 8): ";
    cin >> ancho;

    cout << "Ingrese alto (minimo 8): ";
    cin >> alto;

    if(ancho < 8 || alto < 8 || ancho % 8 != 0)
    {
        cout << "Dimensiones invalidas." << endl;
        return 0;
    }

    unsigned char** tablero;

    crear_Tablero(tablero, alto, ancho);
    inicializar_Tablero(tablero, alto, ancho / 8);

    unsigned char forma[4];

    int tipo = 0;
    int rotacion = 0;

    generar_Pieza(forma, tipo, rotacion);

    int filaPieza = 0;
    int columnaPieza = 2;

    imprimir_Tablero(tablero, alto, ancho, forma, filaPieza, columnaPieza);

    liberar_Tablero(tablero, alto);

    return 0;
}

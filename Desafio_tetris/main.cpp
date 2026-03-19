#include <iostream>
#include "tablero.h"
#include "piezas.h"
#include "movimiento.h"

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
    inicializar_Tablero(tablero, alto, ancho/8);

    unsigned char forma[4];
    int tipo = 0;
    int rotacion = 0;

    generar_Pieza(forma, tipo, rotacion);

    int filaPieza = 0;
    int columnaPieza = (ancho/2) - 2;

    char tecla;
    bool jugando = true;

    while(jugando)
    {
        imprimir_Tablero(tablero, alto, ancho, forma, filaPieza, columnaPieza);

        cin >> tecla;

        switch(tecla)
        {
        case 'a':
            mover_Izquierda(tablero, alto, ancho, forma, filaPieza, columnaPieza);
            break;

        case 'd':
            mover_Derecha(tablero, alto, ancho, forma, filaPieza, columnaPieza);
            break;

        case 's':
            mover_Abajo(tablero, alto, ancho, forma, filaPieza, columnaPieza);
            break;

        case 'w':
            rotacion++;
            generar_Pieza(forma, tipo, rotacion);
            break;

        case 'q':
            jugando = false;
            break;
        }

        cout << "\n\n\n\n\n\n\n\n\n\n";
    }

    liberar_Tablero(tablero, alto);

    return 0;
}

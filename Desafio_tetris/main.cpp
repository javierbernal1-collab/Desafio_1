#include <iostream>
#include "tablero.h"
#include "piezas.h"
#include "movimiento.h"

using namespace std;

int main()
{
    int ancho, alto;

    cout << "Ingrese ancho (minimo 8): ";
    cin >> ancho;

    cout << "Ingrese alto (minimo 8): ";
    cin >> alto;
    if (ancho < 8 || alto < 8 || ancho % 8 != 0)
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
            if(!mover_Abajo(tablero, alto, ancho, forma, filaPieza, columnaPieza))
            {
                fijar_Pieza(tablero, alto, ancho, forma, filaPieza, columnaPieza);

                eliminar_Filas_Completas(tablero, alto, ancho);

                filaPieza = 0;
                columnaPieza = (ancho / 2) - 2;
                rotacion = 0;
                tipo = (tipo + 1) % 7;

                generar_Pieza(forma, tipo, rotacion);

                if(!posicion_Valida(tablero, alto, ancho, forma, filaPieza, columnaPieza))
                {
                    system("cls");
                    imprimir_Tablero(tablero, alto, ancho, forma, filaPieza, columnaPieza);

                    cout << " ===== GAME OVER ===== ";
                    liberar_Tablero(tablero, alto);
                    return 0;
                }

            }

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

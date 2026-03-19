#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

bool mover_Izquierda(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int &filaPieza, int &columnaPieza);

bool mover_Derecha(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int &filaPieza, int &columnaPieza);

bool mover_Abajo(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int &filaPieza, int &columnaPieza);


#endif // MOVIMIENTO_H

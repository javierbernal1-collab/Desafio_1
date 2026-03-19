#ifndef TABLERO_H
#define TABLERO_H

void crear_Tablero(unsigned char** &tablero, int alto, int ancho);

void inicializar_Tablero(unsigned char** tablero, int alto, int bytes);

void imprimir_Tablero(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int fila_Pieza, int columna_Pieza);

bool posicion_Valida(unsigned char** tablero, int alto, int ancho, unsigned char forma[4], int filaPieza, int columnaPieza);

void liberar_Tablero(unsigned char** tablero, int alto);

#endif

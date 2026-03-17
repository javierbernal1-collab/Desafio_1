#ifndef TABLERO_H
#define TABLERO_H

void crear_Tablero(unsigned char** &tablero, int alto, int ancho);
void inicializar_Tablero(unsigned char** tablero, int alto, int bytes);
void imprimir_Tablero(unsigned char** tablero, int alto, int ancho);
void liberar_Tablero(unsigned char** tablero, int alto);

#endif

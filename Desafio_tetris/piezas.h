#ifndef PIEZAS_H
#define PIEZAS_H

void limpiar_Forma(unsigned char forma[4]);

void generar_Pieza(unsigned char forma[4], int tipo, int rotacion);

void rotar_Pieza(unsigned char forma[4], int tipo, int &rotacion);

#endif // PIEZAS_H

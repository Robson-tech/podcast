#ifndef IMPRIMIR_H_INCLUDED
#define IMPRIMIR_H_INCLUDED
#include "../modelos/plataforma.h"

void menuImprimir(Plataforma *plataformas, void* (*buscar)(void*, void*), void (*imprimir)(void*));
void opcoesImprimir();

#endif

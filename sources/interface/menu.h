#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include "../modelos/plataforma.h"

void opcoes();
void menu(
	Plataforma *plataformas,
	void* (*buscar)(void*, void*),
	void (*imprimir)(void*),
	void (*inserir)(void*, void*),
	void* (*criar)(void*(*)(void*), int, void(*)(void*)),
	void (*remover)(void*, void*)
);

#endif

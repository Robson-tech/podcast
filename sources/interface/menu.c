#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "buscar.h"
#include "imprimir.h"
#include "inserir.h"
#include "remover.h"

void opcoes() {
	printf(
		"1 - Buscar\n"
		"2 - Imprimir\n"
		"3 - Inserir\n"
		"4 - Remover\n"
		"0 - Sair\n"
	);
}

void menu(
	Plataforma *plataformas,
	void* (*buscar)(void*, void*),
	void (*imprimir)(void*),
	void (*inserir)(void*, void*),
	void* (*criar)(void*(*)(void*), int, void(*)(void*)),
	void (*remover)(void*, void*),
	int (*temItens)(void*)
) {
	int opc;
	
	do {
		opcoes();
		scanf("%d", &opc); getchar();
		switch(opc) {
			case 1:
				menuBuscar(plataformas, buscar);
				break;
			case 2:
				menuImprimir(plataformas, buscar, imprimir);
				break;
			case 3:
				menuInserir(&plataformas, buscar, inserir, criar);
				break;
			case 4:
				menuRemover(&plataformas, buscar, remover, temItens);
				break;
			case 0:
				break;
			default:
				printf("Opcao nao disponivel\n");
		}
	} while(opc);
}

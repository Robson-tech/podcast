#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imprimir.h"
#include "buscar.h"
#include "../modelos/podcast.h"
#include "../modelos/tema.h"
#include "../modelos/entrevista.h"

void menuImprimir(Plataforma *plataformas, void* (*buscar)(void*, void*), void (*imprimir)(void*)) {
	int opc;
	
	do {
		opcoesImprimir();
		scanf("%d", &opc); getchar();
		switch(opc) {
			case 1:
				imprimirListaPlataforma(plataformas);
				break;
			case 2:
				imprimir(getPodcasts(buscarInterfacePlataforma(plataformas)));
				break;
			case 3:
				imprimir(getTemas(buscarInterfacePodcast(
					getPodcasts(
						buscarInterfacePlataforma(plataformas)
					), buscar)
				));
				break;
			case 4:
				imprimir(getEntrevistas(buscarInterfaceTema(
					getTemas(buscarInterfacePodcast(getPodcasts(
						buscarInterfacePlataforma(plataformas)
					), buscar)
				), buscar)));
				break;
			case 0:
				break;
			default:
				printf("Opcao nao disponivel\n");
		}
	} while(opc);
}

void opcoesImprimir() {
	printf(
		"1 - Imprimir Plataformas\n"
		"2 - Imprimir Podcasts\n"
		"3 - Imprimir Temas\n"
		"4 - Imprimir Entrevistas\n"
		"0 - Voltar\n"
	);
}

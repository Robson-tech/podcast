#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buscar.h"

void menuBuscar(Plataforma *plataformas, void* (*buscar)(void*, void*)) {
	int opc;
	
	do {
		opcoesBuscar();
		scanf("%d", &opc); getchar();
		switch(opc) {
			case 1:
				imprimirPlataforma(buscarInterfacePlataforma(plataformas));
				break;
			case 2:
				imprimirPodcast(buscarInterfacePodcast(getPodcasts(
					buscarInterfacePlataforma(plataformas)
				), buscar));
				break;
			case 3:
				imprimirTema(buscarInterfaceTema(getTemas(
					buscarInterfacePodcast(getPodcasts(
						buscarInterfacePlataforma(plataformas)
					), buscar)
				), buscar));
				break;
			case 4:
				imprimirEntrevista(buscarInterfaceEntrevista(getEntrevistas(
					buscarInterfaceTema(getTemas(
						buscarInterfacePodcast(
							getPodcasts(buscarInterfacePlataforma(plataformas)
						), buscar)
					), buscar)
				), buscar));
				break;
			case 0:
				break;
			default:
				printf("Opcao nao disponivel\n");
		}
	} while(opc);
}

void opcoesBuscar() {
	printf(
		"1 - Buscar Plataforma\n"
		"2 - Buscar Podcast\n"
		"3 - Buscar Tema\n"
		"4 - Buscar Entrevista\n"
		"0 - Voltar\n"
	);
}

Plataforma* buscarInterfacePlataforma(Plataforma *plataformas) {
	Plataforma *busca = NULL;
	char nome[100];
	
	if(plataformas) {
		do {
			printf("Plataforma: ");
			scanf("%99[^\n]s", nome); getchar();
			if(strcmp(nome, "0") == 0) break;
		} while((busca = buscarPlataforma(plataformas, nome)) == NULL);
	}
	return busca;
}

Podcast* buscarInterfacePodcast(void *podcasts, void* (*buscar)(void*, void*)) {
	Podcast *busca = NULL;
	char nome[100];
	
	if(podcasts) {
		do {
			printf("Podcast: ");
			scanf("%99[^\n]s", nome); getchar();
			if(strcmp(nome, "0") == 0) break;
		} while((busca = (Podcast*) buscar(podcasts, nome)) == NULL);
	}
	return busca;
}

Tema* buscarInterfaceTema(void *temas, void* (*buscar)(void*, void*)) {
	Tema *busca = NULL;
	char tipo[50];
	
	if(temas) {
		do {
			printf("Tema: ");
			scanf("%49[^\n]s", tipo); getchar();
			if(strcmp(tipo, "0") == 0) break;
		} while((busca = (Tema*) buscar(temas, tipo)) == NULL);
	}
	return busca;
}

Entrevista* buscarInterfaceEntrevista(void *entrevistas, void* (*buscar)(void*, void*)) {
	Entrevista *busca = NULL;
	char titulo[100];
	
	if(entrevistas) {
		do {
			printf("Entrevista: ");
			scanf("%99[^\n]s", titulo); getchar();
			if(strcmp(titulo, "0") == 0) break;
		} while((busca = (Entrevista*) buscar(entrevistas, titulo)) == NULL);
	}
	return busca;
}

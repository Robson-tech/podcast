#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "remover.h"
#include "buscar.h"

void opcoesRemover() {
	printf(
		"1 - Remover Plataforma\n"
		"2 - Remover Podcast\n"
		"3 - Remover Tema\n"
		"4 - Remover Entrevista\n"
		"0 - Voltar\n"
	);
}

void menuRemover(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*remover)(void*, void*)) {
	int opc;
	
	do {
		opcoesRemover();
		scanf("%d", &opc); getchar();
		switch(opc) {
			case 1:
				removerInterfacePlataforma(plataformas);
				break;
			case 2:
				removerInterfacePodcast(getPodcasts(buscarInterfacePlataforma(*plataformas)), buscar, remover);
				break;
			case 3:
//				imprimirTema(buscarInterfaceTema(getTemas(
//					buscarInterfacePodcast(getPodcasts(
//						buscarInterfacePlataforma(plataformas)
//					), buscar)
//				), buscar));
				break;
			case 4:
//				imprimirEntrevista(buscarInterfaceEntrevista(getEntrevistas(
//					buscarInterfaceTema(getTemas(
//						buscarInterfacePodcast(
//							getPodcasts(buscarInterfacePlataforma(plataformas)
//						), buscar)
//					), buscar)
//				), buscar));
				break;
			case 0:
				break;
			default:
				printf("Opcao nao disponivel\n");
		}
	} while(opc);
}

void removerInterfacePlataforma(Plataforma **plataformas) {
	Plataforma *busca = NULL;
	char nome[100];
	
	if(plataformas) {
		do {
			printf("Plataforma: ");
			scanf("%99[^\n]s", nome); getchar();
			busca = buscarPlataforma(*plataformas, nome);
			if(getPodcasts(busca) != NULL) {
				printf("Plataforma possui Podcasts cadastrados\n");
				busca = NULL;
			}
		} while(strcmp(nome, "0") != 0 && busca == NULL);
		if(busca)
			removerPlataforma(plataformas, nome);
	}
}

void removerInterfacePodcast(void *podcasts, void* (*buscar)(void*, void*), void (*remover)(void*, void*)) {
	Podcast *busca = NULL;
	char nome[100];
	
	if(podcasts) {
		do {
			printf("Podcast: ");
			scanf("%99[^\n]s", nome); getchar();
			busca = (Podcast*) buscar(podcasts, nome);
			if(getTemas(busca) != NULL) {
				printf("Podcast possui Temas cadastrados\n");
				busca = NULL;
			}
		} while(strcmp(nome, "0") != 0 && busca == NULL);
		if(busca)
			remover(podcasts, nome);
	}
}

//Tema* buscarInterfaceTema(void *temas, void* (*buscar)(void*, void*)) {
//	Tema *busca = NULL;
//	char tipo[50];
//	
//	if(temas) {
//		do {
//			printf("Tema: ");
//			scanf("%49[^\n]s", tipo); getchar();
//			if(strcmp(tipo, "0") == 0) break;
//		} while((busca = (Tema*) buscar(temas, tipo)) == NULL);
//	}
//	return busca;
//}
//
//Entrevista* buscarInterfaceEntrevista(void *entrevistas, void* (*buscar)(void*, void*)) {
//	Entrevista *busca = NULL;
//	char titulo[100];
//	
//	if(entrevistas) {
//		do {
//			printf("Entrevista: ");
//			scanf("%99[^\n]s", titulo); getchar();
//			if(strcmp(titulo, "0") == 0) break;
//		} while((busca = (Entrevista*) buscar(entrevistas, titulo)) == NULL);
//	}
//	return busca;
//}

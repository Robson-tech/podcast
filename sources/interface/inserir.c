#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inserir.h"
#include "buscar.h"

void opcoesInserir() {
	printf(
		"1 - Inserir Plataformas\n"
		"2 - Inserir Podcasts\n"
		"3 - Inserir Temas\n"
		"4 - Inserir Entrevistas\n"
		"0 - Voltar\n"
	);
}

void menuInserir(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*inserir)(void*, void*), void* (*criar)(void*(*)(void*), int, void(*)(void*))) {
	int opc;
	
	do {
		opcoesInserir();
		scanf("%d", &opc); getchar();
		switch(opc) {
			case 1:
				inserirPlataforma(plataformas, formularioPlataforma(criar));
				break;
			case 2:
				inserirPodcast(plataformas, buscar, inserir, criar);
				break;
			case 3:
				inserirTema(plataformas, buscar, inserir, criar);
				break;
			case 4:
				inserirEntrevista(plataformas, buscar, inserir, criar);
				break;
			case 0:
				break;
			default:
				printf("Opcao nao disponivel\n");
		}
	} while(opc);
}

Podcast* inserirPodcast(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*inserir)(void*, void*), void* (*criar)(void*(*)(void*), int, void(*)(void*))) {
	Plataforma *plataforma = NULL;
	Podcast *novo = NULL;
	plataforma = buscarInterfacePlataforma(*plataformas);
	if(plataforma) {
		if(getPodcasts(plataforma) == NULL)
			setPodcasts(plataforma, criar(&getChavePodcast, 1, &imprimirPodcast));
		novo = formularioPodcast(criar);
		inserir(getPodcasts(plataforma), novo);
	}
	return novo;
}

Tema* inserirTema(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*inserir)(void*, void*), void* (*criar)(void*(*)(void*), int, void(*)(void*))) {
	Plataforma *plataforma = NULL;
	Podcast *podcast = NULL;
	Tema *novo = NULL;
	plataforma = buscarInterfacePlataforma(*plataformas);
	if(plataforma && getPodcasts(plataforma)) {
		podcast = buscarInterfacePodcast(getPodcasts(plataforma), buscar);
		if(podcast) {
			if(getTemas(podcast) == NULL)
				setTemas(podcast, criar(&getChaveTema, 1, &imprimirTema));
			novo = formularioTema(criar);
			inserir(getTemas(podcast), novo);
		}
	}
	return novo;
}

Entrevista* inserirEntrevista(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*inserir)(void*, void*), void* (*criar)(void*(*)(void*), int, void(*)(void*))) {
	Plataforma *plataforma = NULL;
	Podcast *podcast = NULL;
	Tema *tema = NULL;
	Entrevista *nova = NULL;
	plataforma = buscarInterfacePlataforma(*plataformas);
	if(plataforma && getPodcasts(plataforma)) {
		podcast = buscarInterfacePodcast(getPodcasts(plataforma), buscar);
		if(podcast && getTemas(podcast)) {
			tema = buscarInterfaceTema(getTemas(podcast), buscar);
			if(getEntrevistas(tema) == NULL)
				setEntrevistas(tema, criar(&getChaveEntrevista, 1, &imprimirEntrevista));
			nova = formularioEntrevista(criar);
			inserir(getEntrevistas(tema), nova);
		}
	}
	return nova;
}

Plataforma* formularioPlataforma(void* (*criar)(void*(*)(void*), int, void(*)(void*))) {
	Plataforma *nova = NULL;
	char nome[100];
	printf("Nome: ");
	scanf("%99[^\n]s", nome);
	nova = criarPlataforma(nome, criar(&getChavePodcast, 1, &imprimirPodcast));
	return nova;
}

Podcast* formularioPodcast(void* (*criar)(void*(*)(void*), int, void(*)(void*))) {
	Podcast *novo = NULL;
	char nome[50];
	char entrevistador[100];
	printf("Nome: ");
	scanf("%49[^\n]s", nome); getchar();
	printf("Entrevistador: ");
	scanf("%99[^\n]s", entrevistador); getchar();
	novo = criarPodcast(nome, entrevistador, criar(&getChaveTema, 1, &imprimirTema));
	return novo;
}

Tema* formularioTema(void* (*criar)(void*(*)(void*), int, void(*)(void*))) {
	Tema *novo = NULL;
	char tipo[50];
	char entrevistador[100];
	printf("Tipo: ");
	scanf("%49[^\n]s", tipo); getchar();
	novo = criarTema(tipo, criar(&getChaveEntrevista, 1, &imprimirEntrevista));
	return novo;
}

Entrevista* formularioEntrevista() {
	Entrevista *nova = NULL;
	char titulo[100];
	char data[11];
	int duracao;
	char entrevistado[100];
	char especialidade[50];
	printf("Titulo: ");
	scanf("%99[^\n]s", titulo); getchar();
	printf("Data: ");
	scanf("%10s", data); getchar();
	printf("Duracao: ");
	scanf("%d", &duracao); getchar();
	printf("Entrevistado: ");
	scanf("%99[^\n]s", entrevistado); getchar();
	printf("Especialidade: ");
	scanf("%49[^\n]s", especialidade); getchar();
	nova = criarEntrevista(titulo, data, duracao, entrevistado, especialidade);
	return nova;
}

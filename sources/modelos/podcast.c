#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "podcast.h"

struct podcast {
	char nome[50];
	char entrevistador[100];
	void *temas; // Quando for implementar outros tipos de arvore, lembrar de usar void* para desacoplar e evitar problemas
};

Podcast* criarPodcast(char *nome, char *entrevistador, void *temas) {
	Podcast *novo = NULL;
	novo = (Podcast*) malloc(sizeof(Podcast));
	if(novo) {
		strcpy(novo->nome, nome);
		strcpy(novo->entrevistador, entrevistador);
		novo->temas = temas;
	}
	return novo;
}

void* getChavePodcast(void *estrutura) { return (void*) ((Podcast*)estrutura)->nome; }

void* getTemas(Podcast *podcast) { return (podcast) ? podcast->temas : NULL; }

void* setTemas(Podcast *podcast, void *estrutura) { if (podcast) podcast->temas = estrutura; }

void imprimirPodcast(void *estrutura) {
	if(estrutura) {
		Podcast *podcast = (Podcast*) estrutura;
		printf(
//			"%-20s"
			"%s\n",
			podcast->nome
//			, podcast->entrevistador
		);
//		imprimirArvore(podcast->temas);
	}
}

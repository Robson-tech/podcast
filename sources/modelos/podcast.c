#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "podcast.h"
#include "../binaria/arvore.h"

struct podcast {
	char nome[50];
	char entrevistador[100];
	Arvore *temas;
};

int validadorPodcast(void *estrutura1, void *estrutura2) {
	Podcast *podcast1 = (Podcast*) estrutura1;
	Podcast *podcast2 = (Podcast*) estrutura2;
	return strcmp(podcast1->nome, podcast2->nome);
}

Podcast* criarPodcast(char *nome, char *entrevistador, Arvore *temas) {
	Podcast *novo = NULL;
	novo = (Podcast*) malloc(sizeof(Podcast));
	if(novo) {
		strcpy(novo->nome, nome);
		strcpy(novo->entrevistador, entrevistador);
		novo->temas = temas;
	}
	return novo;
}

void imprimirPodcast(void *estrutura) {
	Podcast *podcast = (Podcast*) estrutura;
	printf("%s\n%s\n", podcast->nome, podcast->entrevistador);
//	imprimirArvore(podcast->temas);
}

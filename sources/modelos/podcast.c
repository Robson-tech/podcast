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

void* getChavePodcast(void *estrutura) {return (void*) ((Podcast*)estrutura)->nome;}

void imprimirPodcast(void *estrutura) {
	Podcast *podcast = (Podcast*) estrutura;
	printf("%s\n%s\n", podcast->nome, podcast->entrevistador);
//	imprimirArvore(podcast->temas);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plataforma.h"
#include "../binaria/arvore.h"

struct plataforma {
	char nome[100];
	Arvore *podcasts;
	struct plataforma *prox;
};

Plataforma* criarPlataforma(char *nome, Arvore *podcasts) {
	Plataforma *nova = NULL;
	nova = (Plataforma*) malloc(sizeof(Plataforma));
	if(nova) {
		strcpy(nova->nome, nome);
		nova->podcasts = podcasts;
		nova->prox = NULL;
	}
	return nova;
}

Plataforma* buscarPlataforma(Plataforma *lista, char *nome) {
	Plataforma *busca = NULL;
	while(lista && busca == NULL) {
		if(strcmp(nome, lista->nome) == 0)
			busca = lista;
		lista = lista->prox;
	}
	return busca;
}

void inserirPlataforma(Plataforma **plataforma, Plataforma *nova) {
	if(plataforma) {
		nova->prox = *plataforma;
		*plataforma = nova;
	}
}

void imprimirPlataforma(Plataforma *lista) {
	while(lista) {
		printf("%s\n", lista->nome);
		lista = lista->prox;
	}
}

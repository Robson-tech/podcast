#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plataforma.h"

struct plataforma {
	char nome[100];
	void *podcasts; // Quando for implementar outros tipos de arvore, lembrar de usar void* para desacoplar e evitar problemas
	struct plataforma *prox;
};

Plataforma* criarPlataforma(char *nome, void *podcasts) {
	Plataforma *nova = NULL;
	nova = (Plataforma*) malloc(sizeof(Plataforma));
	if(nova) {
		strcpy(nova->nome, nome);
		nova->podcasts = podcasts;
		nova->prox = NULL;
	}
	return nova;
}

void* getPodcasts(Plataforma *plataforma) { return (plataforma) ? plataforma->podcasts : NULL; }

void setPodcasts(Plataforma *plataforma, void *estrutura) { if(plataforma) plataforma->podcasts = estrutura; }

Plataforma* buscarPlataforma(Plataforma *lista, char *nome) {
	Plataforma *busca = NULL;
	while(lista && busca == NULL) {
		if(strcmp(nome, lista->nome) == 0)
			busca = lista;
		lista = lista->prox;
	}
	return busca;
}

void inserirPlataforma(Plataforma **lista, Plataforma *nova) {
	if(lista) {
		nova->prox = *lista;
		*lista = nova;
	}
}

void removerPlataforma(Plataforma **lista, char *nome) {
	Plataforma *aux = NULL;
	Plataforma *remover = NULL;
	if(*lista) {
		aux = *lista;
		if(strcmp(nome, aux->nome) == 0) {
			*lista = aux->prox;
			remover = aux;
		} else {
			while(aux->prox && strcmp(nome, aux->prox->nome) != 0)
				aux = aux->prox;
			if(aux->prox) {
				remover = aux->prox;
				aux->prox = remover->prox;
			}
		}
		if(remover) {
			free(remover->podcasts);
			free(remover);
		}
	}
}

void imprimirPlataforma(Plataforma *plataforma) {
	if(plataforma) {
		printf("%s\n", plataforma->nome);
//		imprimirArvore(plataforma->podcasts);
	}
}

void imprimirListaPlataforma(Plataforma *lista) {
	while(lista) {
		imprimirPlataforma(lista);
		lista = lista->prox;
	}
}

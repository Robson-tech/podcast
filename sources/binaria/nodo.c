#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct nodo {
	void *estrutura;
	struct nodo *esq;
	struct nodo *dir;
};

Nodo* criarNodo(void *estrutura) {
	Nodo *novo = NULL;
	novo = (Nodo*) malloc(sizeof(Nodo));
	if(novo) {
		novo->estrutura = estrutura;
		novo->esq = NULL;
		novo->dir = NULL;
	}
	return novo;
}

void inserirNodo(Nodo **raiz, void *estrutura, int (*validador)(void*, void*)) {
	if(*raiz == NULL)
		*raiz = criarNodo(estrutura);
	else {
		if(validador(estrutura, (*raiz)->estrutura) > 0)
			inserirNodo(&((*raiz)->esq), estrutura, validador);
		else if(validador(estrutura, (*raiz)->estrutura) < 0)
			inserirNodo(&((*raiz)->dir), estrutura, validador);
	}
}

void imprimirNodo(Nodo *raiz, int nivel, void (*impressao)(void*)) {
	int i;
	if(raiz) {
		imprimirNodo(raiz->esq, nivel + 1, impressao);
		for(i = 0; i < nivel; i++)
			printf("\t");
		(*impressao)(raiz->estrutura);
		imprimirNodo(raiz->dir, nivel + 1, impressao);
	}
}

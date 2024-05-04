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

int ehFolha(Nodo *nodo) { return (nodo && nodo->esq == NULL && nodo->dir == NULL) ? 1 : 0; }

void* getEstrutura(Nodo *nodo) { return nodo ? nodo->estrutura : NULL; }

void trocarEstruturasNodo(Nodo *a, Nodo *b) {
	void *aux = a->estrutura;
	a->estrutura = b->estrutura;
	b->estrutura = aux;
}

Nodo** buscarNodo(Nodo **raiz, void *chave, void* (*getChave)(void*), int (*validador)(void*, void*)) {
	Nodo **busca = raiz;
	while(*busca && validador(chave, getChave((*busca)->estrutura)) != 0) {
		if(validador(chave, getChave((*busca)->estrutura)) > 0)
			busca = &((*busca)->esq);
		else if(validador(chave, getChave((*busca)->estrutura)) < 0)
			busca = &((*busca)->dir);
	}
	return busca;
}

void inserirNodo(Nodo **raiz, void *estrutura, void* (*getChave)(void*), int (*validador)(void*, void*)) {
	Nodo **busca = NULL;
	busca = buscarNodo(raiz, getChave(estrutura), getChave, validador);
	if(*busca == NULL) {
		*busca = criarNodo(estrutura);
	}
//	if(*raiz == NULL)
//		*raiz = criarNodo(estrutura);
//	else {
//		if(validador(getChave(estrutura), getChave((*raiz)->estrutura)) > 0)
//			inserirNodo(&((*raiz)->esq), estrutura, validador);
//		else if(validador(getChave(estrutura), getChave((*raiz)->estrutura)) < 0)
//			inserirNodo(&((*raiz)->dir), estrutura, validador);
//	}
}

void removerNodo(Nodo **raiz, void *chave, void* (*getChave)(void*), int (*validador)(void*, void*)) {
	Nodo **busca = NULL;
	Nodo *remover = NULL;
	Nodo *aux = NULL;
	busca = buscarNodo(raiz, chave, getChave, validador);
	if(*busca) {
		if((*busca)->esq && (*busca)->dir) {
			aux = (*busca)->esq;
			while(aux->dir)
				aux = aux->dir;
			trocarEstruturasNodo(*busca, aux);
			removerNodo(&((*busca)->esq), chave, getChave, validador);
		} else if(!ehFolha(*busca)) {
			remover = *busca;
			if((*busca)->esq) *busca = (*busca)->esq;
			else *busca = (*busca)->dir;
		} else {
			remover = *busca;
			*busca = NULL;
		}
		if(remover) {
			free((remover)->estrutura);
			free(remover);
		}
	}
}

void imprimirNodo2(Nodo *raiz, void (*impressao)(void*)) {
	if(raiz) {
		imprimirNodo2(raiz->esq, impressao);
		(*impressao)(raiz->estrutura);
		imprimirNodo2(raiz->dir, impressao);
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

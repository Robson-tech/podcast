#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "nodo.h"

struct arvore {
	Nodo *raiz;
	void* (*getChave)(void*);
	int (*validador)(void*, void*);
	void (*impressao)(void*);
};

int comparadorNumerico(void *chave1, void *chave2) {return *((int*) chave1) - *((int*) chave2);}

int comparadorString(void *chave1, void *chave2) {return strcmp((char*)chave1, (char*)chave2);}

Arvore* construirArvore(void* (*getChave)(void*), int tipo, void (*impressao)(void*)) {
	Arvore *nova = NULL;
	nova = (Arvore*) malloc(sizeof(Arvore));
	if(nova) {
		nova->raiz = NULL;
		nova->getChave = getChave;
		nova->validador = tipo ? &comparadorString: &comparadorNumerico;
		nova->impressao = impressao;
	}
	return nova;
}

void* buscarArvore(Arvore *arvore, void *chave) {
	Nodo **nodo = NULL;
	nodo = buscarNodo(&(arvore->raiz), chave, arvore->getChave, arvore->validador);
	return getEstrutura(*nodo);
}

void inserirArvore(Arvore *arvore, void *elemento) {
	inserirNodo(&(arvore->raiz), elemento, arvore->getChave, arvore->validador);
}

void imprimirNodoArvore(Arvore *arvore, void *nodo) {
	if(nodo)
		arvore->impressao(nodo);
}

void imprimirArvore(Arvore *arvore) {
	imprimirNodo(arvore->raiz, 0, arvore->impressao);
}

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "nodo.h"

struct arvore {
	Nodo *raiz;
	int (*validador)(void*, void*);
	void (*impressao)(void*);
};

Arvore* construirArvore(int (*validador)(void*, void*), void (*impressao)(void*)) {
	Arvore *nova = NULL;
	nova = (Arvore*) malloc(sizeof(Arvore));
	if(nova) {
		nova->raiz = NULL;
		nova->validador = validador;
		nova->impressao = impressao;
	}
	return nova;
}

void inserirArvore(Arvore *arvore, void *elemento) {
	inserirNodo(&(arvore->raiz), elemento, arvore->validador);
}

void imprimirArvore(Arvore *arvore) {
	imprimirNodo(arvore->raiz, 0, arvore->impressao);
}

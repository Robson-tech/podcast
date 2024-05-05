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

void* construirArvore(void* (*getChave)(void*), int tipo, void (*impressao)(void*)) {
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

int temItensBI(void *estrutura) { return (estrutura && ((Arvore*)estrutura)->raiz) ? 1 : 0; }

void* buscarArvore(void *estrutura, void *chave) {
	Arvore *arvore = NULL;
	Nodo **nodo = NULL;
	void *busca = NULL;
	if(estrutura) {
		arvore = (Arvore*) estrutura;
		nodo = buscarNodo(&(arvore->raiz), chave, arvore->getChave, arvore->validador);
		busca = getEstrutura(*nodo);
	}
	return busca;
}

void inserirArvore(void *estrutura, void *elemento) {
	Arvore *arvore = NULL;
	if(estrutura) {
		arvore = (Arvore*) estrutura;
		inserirNodo(&(arvore->raiz), elemento, arvore->getChave, arvore->validador);
	}
}

void removerArvore(void *estrutura, void *chave) {
	Arvore *arvore = NULL;
	void *busca = NULL;
	if(estrutura) {
		arvore = (Arvore*) estrutura;
		removerNodo(&(arvore->raiz), chave, arvore->getChave, arvore->validador);
	}
}

void imprimirNodoArvore(void *estrutura, void *nodo) {
	Arvore *arvore = NULL;
	if(estrutura && nodo) {
		arvore = (Arvore*) estrutura;
		arvore->impressao(nodo);
	}
}

void imprimirArvore(void *estrutura) {
	Arvore *arvore = NULL;
	if(estrutura) {
		arvore = (Arvore*) estrutura;
		imprimirNodo(arvore->raiz, 0, arvore->impressao);
//		imprimirNodo2(arvore->raiz, arvore->impressao);
	}
}

void destruirArvore(void **estrutura) {
	Arvore *arvore = NULL;
	if(estrutura && *estrutura) {
		arvore = (Arvore*) *estrutura;
		destruirNodo(&(arvore->raiz));
		free(arvore);
		*estrutura = NULL;
	}
}

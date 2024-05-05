#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"
#include "nodo_avl.h"

struct arvore_avl {
	NodoAVL *raiz;
	void* (*getChave)(void*);
	int (*validador)(void*, void*);
	void (*impressao)(void*);
};

int comparadorNumericoAVL(void *chave1, void *chave2) {return *((int*) chave1) - *((int*) chave2);}

int comparadorStringAVL(void *chave1, void *chave2) {return strcmp((char*)chave1, (char*)chave2);}

void* construirArvoreAVL(void* (*getChave)(void*), int tipo, void (*impressao)(void*)) {
	ArvoreAVL *nova = NULL;
	nova = (ArvoreAVL*) malloc(sizeof(ArvoreAVL));
	if(nova) {
		nova->raiz = NULL;
		nova->getChave = getChave;
		nova->validador = (tipo) ? &comparadorStringAVL: &comparadorNumericoAVL;
		nova->impressao = impressao;
	}
	return nova;
}

int temItensAVL(void *estrutura) { return (estrutura && ((ArvoreAVL*)estrutura)->raiz) ? 1 : 0; }

void* buscarArvoreAVL(void *estrutura, void *chave) {
	ArvoreAVL *arvore = NULL;
	void *busca = NULL;
	if(estrutura) {
		arvore = (ArvoreAVL*) estrutura;
		NodoAVL **nodo = NULL;
		nodo = buscarNodoAVL(&(arvore->raiz), chave, arvore->getChave, arvore->validador);
		busca = getEstruturaAVL(*nodo);
	}
	return busca;
}

void inserirArvoreAVL(void *estrutura, void *elemento) {
	ArvoreAVL *arvore = NULL;
	if(estrutura) {
		arvore = (ArvoreAVL*) estrutura;
		inserirNodoAVL(&(arvore->raiz), elemento, arvore->getChave, arvore->validador);
	}
}

void removerArvoreAVL(void *estrutura, void *chave) {
	ArvoreAVL *arvore = NULL;
	void *busca = NULL;
	if(estrutura) {
		arvore = (ArvoreAVL*) estrutura;
		removerNodoAVL(&(arvore->raiz), chave, arvore->getChave, arvore->validador);
	}
}

void imprimirNodoArvoreAVL(void *estrutura, void *nodo) {
	ArvoreAVL *arvore = NULL;
	if(estrutura && nodo) {
		arvore = (ArvoreAVL*) estrutura;
		arvore->impressao(nodo);
	}
}

void imprimirArvoreAVL(void *estrutura) {
	ArvoreAVL *arvore = NULL;
	if(estrutura) {
		arvore = (ArvoreAVL*) estrutura;
//		imprimirNodoAVL(arvore->raiz, 0, arvore->impressao);
		imprimirNodoAVL2(arvore->raiz, arvore->impressao);
	}
}

void destruirArvoreAVL(void **estrutura) {
	ArvoreAVL *arvore = NULL;
	if(estrutura && *estrutura) {
		arvore = (ArvoreAVL*) *estrutura;
		destruirNodoAVL(&(arvore->raiz));
		free(arvore);
		*estrutura = NULL;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "nodo_avl.h"

struct nodo_avl {
	void *estrutura;
	int altura;
	struct nodo_avl *esq;
	struct nodo_avl *dir;
};

NodoAVL* criarNodoAVL(void *estrutura) {
	NodoAVL *novo = NULL;
	novo = (NodoAVL*) malloc(sizeof(NodoAVL));
	if(novo) {
		novo->estrutura = estrutura;
		novo->altura = 0;
		novo->esq = NULL;
		novo->dir = NULL;
	}
	return novo;
}

int ehFolhaAVL(NodoAVL *nodo) { return (nodo && nodo->esq == NULL && nodo->dir == NULL) ? 1 : 0; }

void* getEstruturaAVL(NodoAVL *nodo) { return (nodo) ? nodo->estrutura : NULL; }

int getAltura(NodoAVL *nodo) { return (nodo) ? nodo->altura : 0; }

void trocarEstruturasNodoAVL(NodoAVL *a, NodoAVL *b) {
	void *aux = a->estrutura;
	a->estrutura = b->estrutura;
	b->estrutura = aux;
}

NodoAVL** buscarNodoAVL(NodoAVL **raiz, void *chave, void* (*getChave)(void*), int (*validador)(void*, void*)) {
	NodoAVL **busca = raiz;
	while(*busca && validador(chave, getChave((*busca)->estrutura)) != 0) {
		if(validador(chave, getChave((*busca)->estrutura)) > 0)
			busca = &((*busca)->esq);
		else if(validador(chave, getChave((*busca)->estrutura)) < 0)
			busca = &((*busca)->dir);
	}
	return busca;
}

void inserirNodoAVL(NodoAVL **raiz, void *estrutura, void* (*getChave)(void*), int (*validador)(void*, void*)) {
	if(*raiz == NULL)
		*raiz = criarNodoAVL(estrutura);
	else {
		if(validador(getChave(estrutura), getChave((*raiz)->estrutura)) > 0)
			inserirNodoAVL(&((*raiz)->esq), estrutura, getChave, validador);
		else if(validador(getChave(estrutura), getChave((*raiz)->estrutura)) < 0)
			inserirNodoAVL(&((*raiz)->dir), estrutura, getChave, validador);
		(*raiz)->altura = maior(getAltura((*raiz)->esq), getAltura((*raiz)->dir)) + 1;
		balancear(raiz);
	}
}

void removerNodoAVL(NodoAVL **raiz, void *chave, void* (*getChave)(void*), int (*validador)(void*, void*)) {
	NodoAVL **busca = NULL;
	NodoAVL *remover = NULL;
	NodoAVL *aux = NULL;
	busca = buscarNodoAVL(raiz, chave, getChave, validador);
	if(*busca) {
		if((*busca)->esq && (*busca)->dir) {
			aux = (*busca)->esq;
			while(aux->dir)
				aux = aux->dir;
			trocarEstruturasNodoAVL(*busca, aux);
			removerNodoAVL(&((*busca)->esq), chave, getChave, validador);
		} else if(!ehFolhaAVL(*busca)) {
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
		(*raiz)->altura = maior(getAltura((*raiz)->esq), getAltura((*raiz)->dir)) + 1;
		balancear(raiz);
	}
}

void imprimirNodoAVL2(NodoAVL *raiz, void (*impressao)(void*)) {
	if(raiz) {
		imprimirNodoAVL2(raiz->esq, impressao);
		(*impressao)(raiz->estrutura);
		imprimirNodoAVL2(raiz->dir, impressao);
	}
}

void imprimirNodoAVL(NodoAVL *raiz, int nivel, void (*impressao)(void*)) {
	int i;
	if(raiz) {
		imprimirNodoAVL(raiz->esq, nivel + 1, impressao);
		for(i = 0; i < nivel; i++)
			printf("\t");
		(*impressao)(raiz->estrutura);
		imprimirNodoAVL(raiz->dir, nivel + 1, impressao);
	}
}

void* destruirNodoAVL(NodoAVL **nodo) {
	if(*nodo) {
		destruirNodoAVL(&((*nodo)->esq));
		free((*nodo)->estrutura);
		destruirNodoAVL(&((*nodo)->dir));
		free(*nodo);
		*nodo = NULL;
	}
}

int maior(int a, int b) { return (a > b) ? a : b; }

void rotacionarEsq(NodoAVL **nodo) {
	NodoAVL *novo, *esq;
	if(*nodo) {
		novo = (*nodo)->dir;
		esq = novo->esq;
		(*nodo)->dir = esq;
		novo->esq = *nodo;
		(*nodo)->altura = maior(getAltura((*nodo)->esq), getAltura((*nodo)->dir)) + 1;
		novo->altura = maior(getAltura(novo->esq), getAltura(novo->dir)) + 1;
		*nodo = novo;
	}
}

void rotacionarDir(NodoAVL **nodo) {
	NodoAVL *novo, *dir;
	if(*nodo) {
		novo = (*nodo)->esq;
		dir = novo->dir;
		(*nodo)->esq = dir;
		novo->dir = *nodo;
		(*nodo)->altura = maior(getAltura((*nodo)->esq), getAltura((*nodo)->dir)) + 1;
		novo->altura = maior(getAltura(novo->esq), getAltura(novo->dir)) + 1;
		*nodo = novo;
	}
}

void rotacaoDirEsq(NodoAVL **nodo) {
	if(*nodo) {
		rotacionarDir(&((*nodo)->dir));
		rotacionarEsq(nodo);
	}
}

void rotacaoEsqDir(NodoAVL **nodo) {
	if(*nodo) {
		rotacionarEsq(&((*nodo)->esq));
		rotacionarDir(nodo);
	}
}

int fatorBalanceamento(NodoAVL *nodo) { return (nodo) ? getAltura(nodo->esq) - getAltura(nodo->dir) : 0; }

void balancear(NodoAVL **raiz) {
	int fb;
	if(raiz && *raiz) {
		fb = fatorBalanceamento(*raiz);
		if (fb < -1 && fatorBalanceamento((*raiz)->dir) < 0)
			rotacionarEsq(raiz);
		if (fb > 1 && fatorBalanceamento((*raiz)->esq) > 0)
			rotacionarDir(raiz);
		if (fb < -1 && fatorBalanceamento((*raiz)->dir) > 0)
			rotacaoDirEsq(raiz);
		if ( fb > 1 && fatorBalanceamento((*raiz)->esq) < 0)
			rotacaoEsqDir(raiz);
	}
}

#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED
#include "nodo.h"

typedef struct arvore Arvore;

Arvore* construirArvore(void* (*getChave)(void*), int tipo, void (*impressao)(void*));
void* buscarArvore(Arvore *arvore, void *chave);
void inserirArvore(Arvore *arvore, void *elemento);
void imprimirNodoArvore(Arvore *arvore, void *nodo);
void imprimirArvore(Arvore *arvore);

#endif

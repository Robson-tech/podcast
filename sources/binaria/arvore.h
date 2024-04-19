#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED

typedef struct arvore Arvore;

Arvore* construirArvore(int (*validador)(void*, void*), void (*impressao)(void*));
void inserirArvore(Arvore *arvore, void *elemento);
void imprimirArvore(Arvore *arvore);

#endif

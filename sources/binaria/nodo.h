#ifndef NODO_BINARIA_H_INCLUDED
#define NODO_BINARIA_H_INCLUDED

typedef struct nodo Nodo;

Nodo* criarNodo(void *estrutura);
void inserirNodo(Nodo **raiz, void *estrutura, int (*validador)(void*, void*));
void imprimirNodo(Nodo *raiz, int nivel, void (*impressao)(void*));

#endif

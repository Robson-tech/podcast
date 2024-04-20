#ifndef NODO_BINARIA_H_INCLUDED
#define NODO_BINARIA_H_INCLUDED

typedef struct nodo Nodo;

Nodo* criarNodo(void *estrutura);
void* getEstrutura(Nodo *nodo);
Nodo** buscarNodo(Nodo **raiz, void *chave, void* (*getChave)(void*), int (*validador)(void*, void*));
void inserirNodo(Nodo **raiz, void *estrutura, void* (*getChave)(void*), int (*validador)(void*, void*));
void imprimirNodo(Nodo *raiz, int nivel, void (*impressao)(void*));

#endif

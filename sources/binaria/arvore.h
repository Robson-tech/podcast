#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED

typedef struct arvore Arvore;

void* construirArvore(void* (*getChave)(void*), int tipo, void (*impressao)(void*));
int temItensBI(void *estrutura);
void* buscarArvore(void *estrutura, void *chave);
void inserirArvore(void *estrutura, void *elemento);
void removerArvore(void *estrutura, void *chave);
void imprimirNodoArvore(void *estrutura, void *nodo);
void imprimirArvore(void *estrutura);
void destruirArvore(void **estrutura);

#endif

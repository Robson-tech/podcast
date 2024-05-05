#ifndef ARVORE_AVL_H_INCLUDED
#define ARVORE_AVL_H_INCLUDED

typedef struct arvore_avl ArvoreAVL;

void* construirArvoreAVL(void* (*getChave)(void*), int tipo, void (*impressao)(void*));
int temItensAVL(void *estrutura);
void* buscarArvoreAVL(void *estrutura, void *chave);
void inserirArvoreAVL(void *estrutura, void *elemento);
void removerArvoreAVL(void *estrutura, void *chave);
void imprimirNodoArvoreAVL(void *estrutura, void *nodo);
void imprimirArvoreAVL(void *estrutura);
void destruirArvore(void **estrutura);

#endif

#ifndef NODO_AVL_BINARIA_H_INCLUDED
#define NODO_AVL_BINARIA_H_INCLUDED

typedef struct nodo_avl NodoAVL;

NodoAVL* criarNodoAVL(void *estrutura);
void* getEstruturaAVL(NodoAVL *nodo);
NodoAVL** buscarNodoAVL(NodoAVL **raiz, void *chave, void* (*getChave)(void*), int (*validador)(void*, void*));
void inserirNodoAVL(NodoAVL **raiz, void *estrutura, void* (*getChave)(void*), int (*validador)(void*, void*));
void removerNodoAVL(NodoAVL **raiz, void *chave, void* (*getChave)(void*), int (*validador)(void*, void*));
void imprimirNodoAVL2(NodoAVL *raiz, void (*impressao)(void*));
void imprimirNodoAVL(NodoAVL *raiz, int nivel, void (*impressao)(void*));
void* destruirNodoAVL(NodoAVL **nodo);
int maior(int a, int b);
void rotacionarEsq(NodoAVL **nodo);
void rotacionarDir(NodoAVL **nodo);
void rotacaoDirEsq(NodoAVL **nodo);
void rotacaoEsqDir(NodoAVL **nodo);
int fatorBalanceamento(NodoAVL *nodo);
void balancear(NodoAVL **raiz);

#endif

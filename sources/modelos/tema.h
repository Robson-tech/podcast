#ifndef TEMA_H_INCLUDED
#define TEMA_H_INCLUDED
#include "../binaria/arvore.h"

typedef struct tema Tema;

Tema* criarTema(char *tipo, Arvore *entrevistas);
void* getChaveTema(void *estrutura);
void imprimirTema(void *estrutura);

#endif

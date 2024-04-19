#ifndef TEMA_H_INCLUDED
#define TEMA_H_INCLUDED
#include "../binaria/arvore.h"

typedef struct tema Tema;

int validadorTema(void *estrutura1, void *estrutura2);
Tema* criarTema(char *tipo, Arvore *entrevistas);
void imprimirTema(void *estrutura);

#endif

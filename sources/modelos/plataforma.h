#ifndef PLATAFORMA_H_INCLUDED
#define PLATAFORMA_H_INCLUDED
#include "../binaria/arvore.h"

typedef struct plataforma Plataforma;

Plataforma* criarPlataforma(char *nome, Arvore *podcasts);
void interfaceInsercaoPlataforma(int num_params, ...);
void inserirPlataforma(Plataforma **plataforma, Plataforma *nova);
void imprimirPlataforma(Plataforma *lista);

#endif

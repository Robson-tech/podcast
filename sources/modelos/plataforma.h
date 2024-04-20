#ifndef PLATAFORMA_H_INCLUDED
#define PLATAFORMA_H_INCLUDED
#include "../binaria/arvore.h"

typedef struct plataforma Plataforma;

Plataforma* criarPlataforma(char *nome, Arvore *podcasts);
Plataforma* buscarPlataforma(Plataforma *lista, char *nome);
void inserirPlataforma(Plataforma **plataforma, Plataforma *nova);
void imprimirPlataforma(Plataforma *lista);

#endif

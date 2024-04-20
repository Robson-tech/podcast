#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tema.h"
#include "../binaria/arvore.h"

struct tema {
	char tipo[50];
	Arvore *entrevistas;
};

Tema* criarTema(char *tipo, Arvore *entrevistas) {
	Tema *novo = NULL;
	novo = (Tema*) malloc(sizeof(Tema));
	if(novo) {
		strcpy(novo->tipo, tipo);
		novo->entrevistas = entrevistas;
	}
	return novo;
}

void* getChaveTema(void *estrutura) {return (void*) ((Tema*)estrutura)->tipo;}

void imprimirTema(void *estrutura) {
	Tema *tema = (Tema*) estrutura;
	printf("%s\n", tema->tipo);
//	imprimirArvore(tema->entrevistas);
}

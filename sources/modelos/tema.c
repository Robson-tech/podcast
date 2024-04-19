#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tema.h"
#include "../binaria/arvore.h"

struct tema {
	char tipo[50];
	Arvore *entrevistas;
};

int validadorTema(void *estrutura1, void *estrutura2) {
	Tema *tema1 = (Tema*) estrutura1;
	Tema *tema2 = (Tema*) estrutura2;
	return strcmp(tema1->tipo, tema2->tipo);
}

Tema* criarTema(char *tipo, Arvore *entrevistas) {
	Tema *novo = NULL;
	novo = (Tema*) malloc(sizeof(Tema));
	if(novo) {
		strcpy(novo->tipo, tipo);
		novo->entrevistas = entrevistas;
	}
	return novo;
}

void imprimirTema(void *estrutura) {
	Tema *tema = (Tema*) estrutura;
	printf("%s\n", tema->tipo);
//	imprimirArvore(tema->entrevistas);
}

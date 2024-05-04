#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tema.h"

struct tema {
	char tipo[50];
	void *entrevistas; // Quando for implementar outros tipos de arvore, lembrar de usar void* para desacoplar e evitar problemas
};

Tema* criarTema(char *tipo, void *entrevistas) {
	Tema *novo = NULL;
	novo = (Tema*) malloc(sizeof(Tema));
	if(novo) {
		strcpy(novo->tipo, tipo);
		novo->entrevistas = entrevistas;
	}
	return novo;
}

void* getChaveTema(void *estrutura) {return (void*) ((Tema*)estrutura)->tipo;}

void *getEntrevistas(Tema *tema) { return (tema) ? tema->entrevistas : NULL; }

void *setEntrevistas(Tema *tema, void *estrutura) { if (tema) tema->entrevistas = estrutura; }

void imprimirTema(void *estrutura) {
	if(estrutura) {
		Tema *tema = (Tema*) estrutura;
		printf("%s\n", tema->tipo);
//		imprimirArvore(tema->entrevistas);
	}
}

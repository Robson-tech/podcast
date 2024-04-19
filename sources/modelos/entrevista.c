#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrevista.h"

struct entrevista {
	char titulo[100];
	char data[11];
	int duracao;
	char entrevistado[100];
	char especialidade[50];
};

int validadorEntrevista(void *estrutura1, void *estrutura2) {
	Entrevista *entrevista1 = (Entrevista*) estrutura1;
	Entrevista *entrevista2 = (Entrevista*) estrutura2;
	return strcmp(entrevista1->titulo, entrevista2->titulo);
}

Entrevista* criarEntrevista(char *titulo, char *data, int duracao, char *entrevistado, char *especialidade) {
	Entrevista *nova = NULL;
	nova = (Entrevista*) malloc(sizeof(Entrevista));
	if(nova) {
		strcpy(nova->titulo, titulo);
		strcpy(nova->data, data);
		nova->duracao = duracao;
		strcpy(nova->entrevistado, entrevistado);
		strcpy(nova->especialidade, especialidade);
	}
	return nova;
}

void imprimirEntrevista(void *estrutura) {
	Entrevista *entrevista = (Entrevista*) estrutura;
	printf(
		"%s\n"
//		"%s\n%d\n%s\n%s\n"
		, entrevista->titulo
//		, entrevista->data, entrevista->duracao, entrevista->entrevistado, entrevista->especialidade
	);
}

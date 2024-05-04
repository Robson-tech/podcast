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

void* getChaveEntrevista(void *estrutura) {return (void*) ((Entrevista*)estrutura)->titulo;}

void imprimirEntrevista(void *estrutura) {
	if(estrutura) {
		Entrevista *entrevista = (Entrevista*) estrutura;
		printf(
			"%-20s\n"
//			"%-12s%-5d%-25s%-20s\n"
			, entrevista->titulo
//			, entrevista->data, entrevista->duracao, entrevista->entrevistado, entrevista->especialidade
		);
	}
}

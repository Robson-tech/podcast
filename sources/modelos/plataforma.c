#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "plataforma.h"
#include "../binaria/arvore.h"

struct plataforma {
	char nome[100];
	Arvore *podcasts;
	struct plataforma *prox;
};

Plataforma* criarPlataforma(char *nome, Arvore *podcasts) {
	Plataforma *nova = NULL;
	nova = (Plataforma*) malloc(sizeof(Plataforma));
	if(nova) {
		strcpy(nova->nome, nome);
		nova->podcasts = podcasts;
		nova->prox = NULL;
	}
	return nova;
}

void interfaceInsercaoPlataforma(int num_params, ...) {
	Plataforma *nova = NULL;
	va_list params;
	va_start(params, num_params);
	nova = criarPlataforma(va_arg(params, char*), va_arg(params, Arvore*));
	if(nova)
		inserirPlataforma(va_arg(params, Plataforma**), nova);
	va_end(params);
}

void inserirPlataforma(Plataforma **plataforma, Plataforma *nova) {
	if(plataforma) {
		nova->prox = *plataforma;
		*plataforma = nova;
	}
}

void imprimirPlataforma(Plataforma *lista) {
	while(lista) {
		printf("%s\n", lista->nome);
		lista = lista->prox;
	}
}

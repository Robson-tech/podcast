#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "comando.h"

struct comando {
	char *nome;
	char *descricao;
	int num_params;
	void (*funcao)(int, ...);
	Comando *subcomandos;
	struct comando *prox;
};

Comando* criarComando(char *nome, char *descricao, int num_params, void (*funcao)(int, ...), Comando *subcomandos) {
	Comando *novo = NULL;
	novo = (Comando*) malloc(sizeof(Comando));
	if(novo) {
		strcpy(novo->nome, nome);
		strcpy(novo->descricao, descricao);
		novo->num_params = num_params;
		novo->funcao = funcao;
		novo->subcomandos = subcomandos;
		novo->prox = NULL;
	}
	return novo;
}

Comando* buscarComando(Comando *lista, char *nome) {
	Comando *busca = NULL;
	while(lista) {
		if(strcmp(nome, lista->nome) == 0) {
			busca = lista;
			break;
		}
		lista = lista->prox;
	}
	return busca;
}

void inserirComando(Comando **lista, Comando *novo) {
	if(lista) {
		novo->prox = *lista;
		*lista = novo;
	}
}

int executarComando(Comando *comando, int num_params, ...) {
	va_list params;
	va_start(params, num_params);
	if(comando && num_params == comando->num_params)
		comando->funcao(num_params, num_params, params);
	va_end(params);
}

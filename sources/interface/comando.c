#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "comando.h"

struct comando {
	char *nome;
	char *descricao;
	int args_num;
	void *args_val;
	void (*funcao)(int, ...);
	struct comando *prox;
};

Comando* criarComando(char *nome, char *descricao, int args_num, void (*funcao)(int, ...)) {
	Comando *novo = NULL;
	novo = (Comando*) malloc(sizeof(Comando));
	if(novo) {
		strcpy(novo->nome, nome);
		strcpy(novo->descricao, descricao);
		novo->args_num = args_num;
		novo->funcao = funcao;
		novo->args_val = NULL;
		novo->prox = NULL;
	}
	return novo;
}

Comando* buscarComando(Comando *lista, char *nome) {
	Comando *busca = NULL;
	while(lista && busca == NULL) {
		if(strcmp(nome, lista->nome) == 0)
			busca = lista;
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

//int executarComando(Comando *comando, int args_num, ...) {
//	va_list params;
//	va_start(params, args_num);
//	if(comando && args_num == comando->args_num)
//		comando->funcao(args_num, args_num, params);
//	va_end(params);
//}

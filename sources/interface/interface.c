#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "comando.h"
#include "input.h"

void executarInterface() {
	Comando *lista = NULL;
	Input *input = NULL;
	char command_line[500] = "";
//	int l = 0, k = 1; //comando
//	int m = 0, p = 1; //params
	int executando = 1, has_com = 0, has_par = 0;
	int i, j;
	
	do {
		printf(">");
		scanf("%499[^\n]s", command_line);
		getchar();
		for(i = 0; executando && i < strlen(command_line); i++) {
			if(command_line[i] == '(') {
//				for(++i; i < len && input[i] != ')'; i++) {
//					if(input[i] == '"' || isdigit(input[i])) {
//						if(params == NULL) {
//							has_par = 1;
//							params = (char**) calloc(1, sizeof(char*));
//							params[m] = (char*) calloc(p, sizeof(char));
//						}
//						if(input[i] == '"') {
//							i++;
//							while(input[i] != '"') {
//								params[m][p - 1] = input[i];
//								p++;
//								params[m] = (char*) realloc(params[m], sizeof(char) * p);
//								i++;
//							}
//							params[m][p - 1] = '\0';
//							m++;
//							p = 1;
//							params = (char**) realloc(params, sizeof(char*) * (m + 1));
//							params[m] = (char*) calloc(p, sizeof(char));
//						} else if(isdigit(input[i])) {
//							params[m][p - 1] = input[i];
//							p++;
//							params[m] = (char*) realloc(params[m], sizeof(char) * p);
//							if(!isdigit(input[i + 1])) {
//								params[m][p - 1] = '\0';
//								m++; p = 1;
//								params = (char**) realloc(params, sizeof(char*) * (m + 1));
//								params[m] = (char*) calloc(p, sizeof(char));
//							}
//						}
//					}
//				}
			} else if(isalpha(command_line[i])) {
//				if(comando == NULL) {
//					has_com = 1;
//					comando = (char**) calloc(1, sizeof(char*));
//					comando[l] = (char*) calloc(k, sizeof(char));
//				}
//				comando[l][k - 1] = input[i];
//				comando[l] = (char*) realloc(comando[l], sizeof(char) * ++k);
//				if(!isalpha(input[i + 1])) {
//					comando[l][k - 1] = '\0';
//					if(strcmp(comando[l], "sair") == 0) executando = 0;
//					l++; k = 1;
//					comando = (char**) realloc(comando, sizeof(char*) * (l + 1));
//					comando[l] = (char*) calloc(k, sizeof(char));
//				}
			}
		}
		if(has_com) {
//			printf("COMANDOS\n");
//			for(i = 0; i < l; i++) {
//				printf("%s %d\n", comando[i], strlen(comando[i]));
//				free(comando[i]);
//			}
//			free(comando[i]);
//			free(comando);
//			comando = NULL;
//			has_com = 0;
//			l = 0; k = 1;
		}
		if(has_par) {
//			printf("PARAMETROS\n");
//			for(i = 0; i < m; i++) {
//				printf("%s %d\n", params[i], strlen(params[i]));
//				free(params[i]);
//			}
//			free(params[i]);
//			free(params);
//			params = NULL;
//			has_par = 0;
//			m = 0; p = 1;
		}
		strcpy(command_line, "");
	} while(executando);
}

void verificarParametros(char *input, int i) {
	
}

void verificarComandos() {
	
}

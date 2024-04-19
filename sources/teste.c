#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "teste.h"
#include "binaria/arvore.h"
#include "interface/comando.h"
#include "modelos/plataforma.h"
#include "modelos/podcast.h"
#include "modelos/tema.h"
#include "modelos/entrevista.h"

void teste() {
	testeInterface();
	
//	char txt[] = "robson jorge isis alisson paulo";
//	char *lista;
//	printf("%s %d\n", txt, strlen(txt));
//	lista = strtok(txt, " ");
//	printf("%s %d\n", lista, strlen(lista));
//	lista = strtok(NULL, " ");
//	printf("%s %d\n", lista, strlen(lista));
//	lista = strtok(NULL, " ");
//	printf("%s %d\n", lista, strlen(lista));
//	lista = strtok(NULL, " ");
//	printf("%s %d\n", lista, strlen(lista));
//	lista = strtok(NULL, " ");
//	printf("%s %d\n", lista, strlen(lista));
//	printf("%s %d\n", txt, strlen(txt));

//	testePodcast();
}

void testeInterface() {
	char **comando = NULL;
	char **params = NULL;
	int l = 0, k = 1; //comando
	int m = 0, p = 1; //params
	char input[500] = "";
	int executando = 1, len = 0, has_com = 0, has_par = 0;
	int i, j;
	
	do {
		printf(">");
		scanf("%499[^\n]s", input);
		len = strlen(input);
		getchar();
		for(i = 0; executando && i < len; i++) {
			if(input[i] == '(') {
				for(++i; i < len && input[i] != ')'; i++) {
					if(input[i] == '"' || isdigit(input[i])) {
						if(params == NULL) {
							has_par = 1;
							params = (char**) calloc(1, sizeof(char*));
							params[m] = (char*) calloc(p, sizeof(char));
						}
						if(input[i] == '"') {
							i++;
							while(input[i] != '"') {
								params[m][p - 1] = input[i];
								p++;
								params[m] = (char*) realloc(params[m], sizeof(char) * p);
								i++;
							}
							params[m][p - 1] = '\0';
							m++;
							p = 1;
							params = (char**) realloc(params, sizeof(char*) * (m + 1));
							params[m] = (char*) calloc(p, sizeof(char));
						} else if(isdigit(input[i])) {
							params[m][p - 1] = input[i];
							p++;
							params[m] = (char*) realloc(params[m], sizeof(char) * p);
							if(!isdigit(input[i + 1])) {
								params[m][p - 1] = '\0';
								m++; p = 1;
								params = (char**) realloc(params, sizeof(char*) * (m + 1));
								params[m] = (char*) calloc(p, sizeof(char));
							}
						}
					}
				}
			} else if(isalpha(input[i])) {
				if(comando == NULL) {
					has_com = 1;
					comando = (char**) calloc(1, sizeof(char*));
					comando[l] = (char*) calloc(k, sizeof(char));
				}
				comando[l][k - 1] = input[i];
				comando[l] = (char*) realloc(comando[l], sizeof(char) * ++k);
				if(!isalpha(input[i + 1])) {
					comando[l][k - 1] = '\0';
					if(strcmp(comando[l], "sair") == 0) executando = 0;
					l++; k = 1;
					comando = (char**) realloc(comando, sizeof(char*) * (l + 1));
					comando[l] = (char*) calloc(k, sizeof(char));
				}
			}
		}
		if(has_com) {
			printf("COMANDOS\n");
			for(i = 0; i < l; i++) {
				printf("%s %d\n", comando[i], strlen(comando[i]));
				free(comando[i]);
			}
			free(comando[i]);
			free(comando);
			comando = NULL;
			has_com = 0;
			l = 0; k = 1;
		}
		if(has_par) {
			printf("PARAMETROS\n");
			for(i = 0; i < m; i++) {
				printf("%s %d\n", params[i], strlen(params[i]));
				free(params[i]);
			}
			free(params[i]);
			free(params);
			params = NULL;
			has_par = 0;
			m = 0; p = 1;
		}
		strcpy(input, "");
	} while(executando);
}

void testePodcast() {
	printf("ENTREVISTAS\n");
	Arvore *diretores = construirArvore(&validadorEntrevista, &imprimirEntrevista);
	inserirArvore(diretores, criarEntrevista("fury road", "14-05-2015", 150, "george miller", "diretor"));
	inserirArvore(diretores, criarEntrevista("matrix", "31-03-1999", 136, "lana wachowski", "diretor"));
	inserirArvore(diretores, criarEntrevista("lord of the rings", "19-12-2001", 178, "peter jackson", "diretor"));
	inserirArvore(diretores, criarEntrevista("star wars", "25-05-1977", 121, "george lucas", "diretor"));
	inserirArvore(diretores, criarEntrevista("the godfather", "24-03-1972", 175, "francis ford coppola", "diretor"));
	imprimirArvore(diretores);
	
	Arvore *animacao = construirArvore(&validadorEntrevista, &imprimirEntrevista);
	inserirArvore(animacao, criarEntrevista("up", "29-05-2009", 96, "pete docter", "animacao"));
	inserirArvore(animacao, criarEntrevista("toy story", "22-11-1995", 81, "john lasseter", "animacao"));
	inserirArvore(animacao, criarEntrevista("finding nemo", "30-05-2003", 100, "andrew stanton", "animacao"));
	inserirArvore(animacao, criarEntrevista("the lion king", "24-06-1994", 88, "roger allers", "animacao"));
	inserirArvore(animacao, criarEntrevista("shrek", "18-05-2001", 90, "andrew adamson", "animacao"));
	imprimirArvore(animacao);

	Arvore *atores = construirArvore(&validadorEntrevista, &imprimirEntrevista);
	inserirArvore(atores, criarEntrevista("drive", "16-09-2011", 100, "ryan gosling", "ator"));
	inserirArvore(atores, criarEntrevista("the dark knight", "18-07-2008", 152, "heath ledger", "ator"));
	inserirArvore(atores, criarEntrevista("avengers", "04-05-2012", 143, "robert downey jr.", "ator"));
	inserirArvore(atores, criarEntrevista("the shawshank redemption", "14-10-1994", 142, "morgan freeman", "ator"));
	inserirArvore(atores, criarEntrevista("cidade de deus", "30-08-2002", 130, "alexandre rodrigues", "ator"));
	imprimirArvore(atores);

	Arvore *escritores = construirArvore(&validadorEntrevista, &imprimirEntrevista);
	inserirArvore(escritores, criarEntrevista("the lord of the rings", "19-12-2001", 178, "j.r.r. tolkien", "escritor"));
	inserirArvore(escritores, criarEntrevista("harry potter", "16-11-2001", 152, "j.k. rowling", "escritor"));
	inserirArvore(escritores, criarEntrevista("dune", "14-12-1984", 137, "frank herbert", "escritor"));
	inserirArvore(escritores, criarEntrevista("the shining", "13-06-1980", 146, "stephen king", "escritor"));
	inserirArvore(escritores, criarEntrevista("monalisa overdrive", "01-06-1988", 100, "william gibson", "escritor"));
	imprimirArvore(escritores);

	Arvore *professores = construirArvore(&validadorEntrevista, &imprimirEntrevista);
	inserirArvore(professores, criarEntrevista("albert einstein", "14-03-1879", 76, "albert einstein", "professor"));
	inserirArvore(professores, criarEntrevista("richard feynman", "11-05-1918", 69, "richard feynman", "professor"));
	inserirArvore(professores, criarEntrevista("carl sagan", "09-11-1934", 62, "carl sagan", "professor"));
	inserirArvore(professores, criarEntrevista("neil degrasse tyson", "05-10-1958", 61, "neil degrasse tyson", "professor"));
	inserirArvore(professores, criarEntrevista("stephen hawking", "08-01-1942", 76, "stephen hawking", "professor"));
	imprimirArvore(professores);
	
	printf("\n\nTEMAS\n");
	Arvore *cinema = construirArvore(&validadorTema, &imprimirTema);
	inserirArvore(cinema, criarTema("filmes", diretores));
	inserirArvore(cinema, criarTema("documentarios", animacao));
	inserirArvore(cinema, criarTema("series", atores));
	imprimirArvore(cinema);

	Arvore *literatura = construirArvore(&validadorTema, &imprimirTema);
	inserirArvore(literatura, criarTema("fantasia", escritores));
	inserirArvore(literatura, criarTema("ficcao cientifica", professores));
	imprimirArvore(literatura);
	
	printf("\n\nPODCASTS\n");
	Arvore *podcast = construirArvore(&validadorPodcast, &imprimirPodcast);
	inserirArvore(podcast, criarPodcast("podpah", "igor cavalari", cinema));
	inserirArvore(podcast, criarPodcast("nerdcast", "azaghal", literatura));
	imprimirArvore(podcast);
	
	printf("\n\nPLATAFORMAS\n");
	Plataforma *youtube = criarPlataforma("youtube", podcast);
	imprimirPlataforma(youtube);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "teste.h"
#include "binaria/arvore.h"
#include "avl/arvore_avl.h"
#include "modelos/plataforma.h"
#include "modelos/podcast.h"
#include "modelos/tema.h"
#include "modelos/entrevista.h"
#include "interface/menu.h"

void teste() {
	testeAVL();
}

char* geradorStrings(const int tam, const int itr) {
	char *texto;
	int tipo[2] = {65, 97};
	int i;
	texto = (char*) malloc(sizeof(char) * tam);
	if(texto) {
		srand(time(NULL) + itr);
		for(i = 0; i < tam - 1; i++)
			texto[i] = (char) (rand() % 26 + tipo[rand() % 2]);
		texto[i] = '\0';
	}
	return texto;
}

char** gerarListaStrings(const int tamLista, const int tamText) {
	char **lista;
	int i;
	lista = (char**) malloc(sizeof(char*) * tamLista);
	if(lista) {
		for(i = 0; i < tamLista; i++)
			lista[i] = geradorStrings(tamText, i);
	}
	return lista;
}

void destruirListaStrings(char **lista, const int tamLista) {
	int i;
	for(i = 0; i < tamLista; i++)
		free(lista[i]);
	free(lista);
}

void testeTempoInsercaoBinaria(const int qntd, const int tamText) {
	Arvore *podcasts = NULL;
	clock_t inicio, fim;
	double tempo, media = 0;
	char **lista;
	int i, j;
	printf("Inserindo %d itens por teste na BINARIA:\n\n", qntd);
	for(i = 0; i < 30; i++) {
		podcasts = construirArvore(&getChavePodcast, 1, &imprimirPodcast);
		lista = gerarListaStrings(qntd, tamText);
		inicio = clock();
		for(j = 0; j < qntd; j++)
			inserirArvore(podcasts, criarPodcast(lista[j], "", NULL));
		fim = clock();
		tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
		media += tempo;
		printf("%02d) Tempo: %.3lf\n", i + 1, tempo);
//		imprimirArvore(podcasts);
//		getchar();
		destruirListaStrings(lista, qntd);
		destruirArvore((void**)&podcasts);
	}
	media /= 30;
	printf("\nMedia: %.3lf\n", media);
}

void testeTempoBuscaBinaria(const int qntd, const int tamText, const int numBuscas) {
	Arvore *podcasts = NULL;
	clock_t inicio, fim;
	double tempo, media = 0;
	char **lista;
	int i, j;
	podcasts = construirArvore(&getChavePodcast, 1, &imprimirPodcast);
	lista = gerarListaStrings(qntd, tamText);
	for(i = 0; i < qntd; i++)
		inserirArvore(podcasts, criarPodcast(lista[i], "", NULL));
	destruirListaStrings(lista, qntd);
//	imprimirArvore(podcasts);
//	getchar();
	printf("Buscando %d em %d itens por teste na BINARIA:\n\n", numBuscas, qntd);
	for(i = 0; i < 30; i++) {
		lista = gerarListaStrings(numBuscas, tamText);
		inicio = clock();
		for(j = 0; j < numBuscas; j++)
			buscarArvore(podcasts, lista[j]);
		fim = clock();
		tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
		media += tempo;
		printf("%02d) Tempo: %.3lf\n", i + 1, tempo);
		destruirListaStrings(lista, numBuscas);
	}
	media /= 30;
	printf("\nMedia: %.3lf\n", media);
	destruirArvore((void**)&podcasts);
}

void testeTempoInsercaoAVL(const int qntd, const int tamText) {
	ArvoreAVL *podcasts = NULL;
	clock_t inicio, fim;
	double tempo, media = 0;
	char **lista;
	int i, j;
	printf("Inserindo %d itens por teste na AVL:\n\n", qntd);
	for(i = 0; i < 30; i++) {
		podcasts = construirArvoreAVL(&getChavePodcast, 1, &imprimirPodcast);
		lista = gerarListaStrings(qntd, tamText);
		inicio = clock();
		for(j = 0; j < qntd; j++)
			inserirArvoreAVL(podcasts, criarPodcast(lista[j], "", NULL));
		fim = clock();
		tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
		media += tempo;
		printf("%02d) Tempo: %.3lf\n", i + 1, tempo);
//		imprimirArvoreAVL(podcasts);
//		getchar();
		destruirListaStrings(lista, qntd);
		destruirArvoreAVL((void**)&podcasts);
	}
	media /= 30;
	printf("\nMedia: %.3lf\n", media);
}

void testeTempoBuscaAVL(const int qntd, const int tamText, const int numBuscas) {
	ArvoreAVL *podcasts = NULL;
	clock_t inicio, fim;
	double tempo, media = 0;
	char **lista;
	int i, j;
	podcasts = construirArvoreAVL(&getChavePodcast, 1, &imprimirPodcast);
	lista = gerarListaStrings(qntd, tamText);
	for(i = 0; i < qntd; i++)
		inserirArvoreAVL(podcasts, criarPodcast(lista[i], "", NULL));
	destruirListaStrings(lista, qntd);
//	imprimirArvoreAVL(podcasts);
//	getchar();
	printf("Buscando %d em %d itens por teste na AVL:\n\n", numBuscas, qntd);
	for(i = 0; i < 30; i++) {
		lista = gerarListaStrings(numBuscas, tamText);
		inicio = clock();
		for(j = 0; j < numBuscas; j++)
			buscarArvoreAVL(podcasts, lista[j]);
		fim = clock();
		tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
		media += tempo;
		printf("%02d) Tempo: %.3lf\n", i + 1, tempo);
		destruirListaStrings(lista, numBuscas);
	}
	media /= 30;
	printf("\nMedia: %.3lf\n", media);
	destruirArvoreAVL((void**)&podcasts);
}

void testeAVL() {
	Plataforma *plataformas = NULL;
	ArvoreAVL *podcasts = NULL;
	ArvoreAVL *temas = NULL;
	ArvoreAVL *entrevistas = NULL;
	
	entrevistas = construirArvoreAVL(&getChaveEntrevista, 1, &imprimirEntrevista);
	inserirArvoreAVL(entrevistas, criarEntrevista("fury road", "14-05-2015", 150, "george miller", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("the matrix", "31-03-1999", 136, "lana wachowski", "diretora"));
	inserirArvoreAVL(entrevistas, criarEntrevista("lord of the rings", "19-12-2001", 178, "peter jackson", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("star wars", "25-05-1977", 121, "george lucas", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("the godfather", "24-03-1972", 175, "francis ford coppola", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("the shawshank redemption", "14-10-1994", 142, "morgan freeman", "ator"));
	inserirArvoreAVL(entrevistas, criarEntrevista("cidade de deus", "30-08-2002", 130, "alexandre rodrigues", "ator"));
	inserirArvoreAVL(entrevistas, criarEntrevista("drive", "16-09-2011", 100, "ryan gosling", "ator"));
	inserirArvoreAVL(entrevistas, criarEntrevista("the dark knight", "18-07-2008", 152, "heath ledger", "ator"));
	inserirArvoreAVL(entrevistas, criarEntrevista("avengers", "04-05-2012", 143, "robert downey jr.", "ator"));
	inserirArvoreAVL(entrevistas, criarEntrevista("harry potter", "16-11-2001", 152, "j.k. rowling", "escritor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("avatar", "18-12-2009", 162, "james cameron", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("titanic", "18-12-1997", 195, "james cameron", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("jurassic park", "11-06-1993", 127, "steven spielberg", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("indiana jones", "12-06-1981", 115, "steven spielberg", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("star trek", "08-05-2009", 127, "j.j. abrams", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("requiem for a dream", "15-12-2000", 102, "darren aronofsky", "diretor"));
	inserirArvoreAVL(entrevistas, criarEntrevista("the social network", "01-10-2010", 120, "david fincher", "diretor"));
//	imprimirArvoreAVL(entrevistas);
	temas = construirArvoreAVL(&getChaveTema, 1, &imprimirTema);
	inserirArvoreAVL(temas, criarTema("filmes", entrevistas));
	inserirArvoreAVL(temas, criarTema("documentarios", NULL));
	inserirArvoreAVL(temas, criarTema("series", NULL));
//	imprimirArvoreAVL(temas);
	podcasts = construirArvoreAVL(&getChavePodcast, 1, &imprimirPodcast);
	inserirArvoreAVL(podcasts, criarPodcast("podpah", "igor cavalari", NULL));
	inserirArvoreAVL(podcasts, criarPodcast("nerdcast", "azaghal", temas));
//	imprimirArvoreAVL(podcasts);
	inserirPlataforma(&plataformas, criarPlataforma("spotify", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("youtube", podcasts));
	inserirPlataforma(&plataformas, criarPlataforma("deezer", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("facebook", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("twitter", NULL));
//	imprimirPlataforma(plataformas);

//	imprimirPlataforma(buscarInterfacePlataforma(plataformas));
//	imprimirPodcast(buscarInterfacePodcast(podcasts));
//	imprimirTema(buscarInterfaceTema(temas));
//	imprimirEntrevista(buscarInterfaceEntrevista(entrevistas));

	menu(plataformas, &buscarArvoreAVL, &imprimirArvoreAVL, &inserirArvoreAVL, &construirArvoreAVL, &removerArvoreAVL, &temItensAVL);
}

void testeInterface() {
	Plataforma *plataformas = NULL;
	Arvore *podcasts = NULL;
	Arvore *temas = NULL;
	Arvore *entrevistas = NULL;
	
	entrevistas = construirArvore(&getChaveEntrevista, 1, &imprimirEntrevista);
	inserirArvore(entrevistas, criarEntrevista("fury road", "14-05-2015", 150, "george miller", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("the matrix", "31-03-1999", 136, "lana wachowski", "diretora"));
	inserirArvore(entrevistas, criarEntrevista("lord of the rings", "19-12-2001", 178, "peter jackson", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("star wars", "25-05-1977", 121, "george lucas", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("the godfather", "24-03-1972", 175, "francis ford coppola", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("the shawshank redemption", "14-10-1994", 142, "morgan freeman", "ator"));
	inserirArvore(entrevistas, criarEntrevista("cidade de deus", "30-08-2002", 130, "alexandre rodrigues", "ator"));
	inserirArvore(entrevistas, criarEntrevista("drive", "16-09-2011", 100, "ryan gosling", "ator"));
	inserirArvore(entrevistas, criarEntrevista("the dark knight", "18-07-2008", 152, "heath ledger", "ator"));
	inserirArvore(entrevistas, criarEntrevista("avengers", "04-05-2012", 143, "robert downey jr.", "ator"));
	inserirArvore(entrevistas, criarEntrevista("harry potter", "16-11-2001", 152, "j.k. rowling", "escritor"));
	inserirArvore(entrevistas, criarEntrevista("avatar", "18-12-2009", 162, "james cameron", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("titanic", "18-12-1997", 195, "james cameron", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("jurassic park", "11-06-1993", 127, "steven spielberg", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("indiana jones", "12-06-1981", 115, "steven spielberg", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("star trek", "08-05-2009", 127, "j.j. abrams", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("requiem for a dream", "15-12-2000", 102, "darren aronofsky", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("the social network", "01-10-2010", 120, "david fincher", "diretor"));
	imprimirArvore(entrevistas);
	temas = construirArvore(&getChaveTema, 1, &imprimirTema);
	inserirArvore(temas, criarTema("filmes", entrevistas));
	inserirArvore(temas, criarTema("documentarios", NULL));
	inserirArvore(temas, criarTema("series", NULL));
//	imprimirArvore(temas);
	podcasts = construirArvore(&getChavePodcast, 1, &imprimirPodcast);
	inserirArvore(podcasts, criarPodcast("podpah", "igor cavalari", NULL));
	inserirArvore(podcasts, criarPodcast("nerdcast", "azaghal", temas));
//	imprimirArvore(podcasts);
	inserirPlataforma(&plataformas, criarPlataforma("spotify", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("youtube", podcasts));
	inserirPlataforma(&plataformas, criarPlataforma("deezer", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("facebook", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("twitter", NULL));
//	imprimirPlataforma(plataformas);

//	imprimirPlataforma(buscarInterfacePlataforma(plataformas));
//	imprimirPodcast(buscarInterfacePodcast(podcasts));
//	imprimirTema(buscarInterfaceTema(temas));
//	imprimirEntrevista(buscarInterfaceEntrevista(entrevistas));

	menu(plataformas, &buscarArvore, &imprimirArvore, &inserirArvore, &construirArvore, &removerArvore, &temItensBI);
}

void testeRemocaoLista() {
	Plataforma *plataformas = NULL;
	inserirPlataforma(&plataformas, criarPlataforma("spotify", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("youtube", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("deezer", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("facebook", NULL));
	inserirPlataforma(&plataformas, criarPlataforma("twitter", NULL));
	imprimirListaPlataforma(plataformas);
	printf("\n\n");
	removerPlataforma(&plataformas, "spotify");
	removerPlataforma(&plataformas, "youtube");
	removerPlataforma(&plataformas, "twitter");
	imprimirListaPlataforma(plataformas);
}

void testeRemocaoArvore() {
	Arvore *entrevistas = NULL;
	entrevistas = construirArvore(&getChaveEntrevista, 1, &imprimirEntrevista);
	inserirArvore(entrevistas, criarEntrevista("4", "14-05-2015", 150, "george miller", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("2", "25-05-1977", 121, "george lucas", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("6", "19-12-2001", 178, "peter jackson", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("1", "31-03-1999", 136, "lana wachowski", "diretora"));
	inserirArvore(entrevistas, criarEntrevista("3", "24-03-1972", 140, "james cameron", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("5", "05-02-1991", 280, "steven spielberg", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("7", "16-11-2015", 104, "edgar wright", "diretor"));
	imprimirArvore(entrevistas);
	printf("\n\n");
	removerArvore(entrevistas, "4");
	removerArvore(entrevistas, "5");
	removerArvore(entrevistas, "2");
	removerArvore(entrevistas, "6");
	removerArvore(entrevistas, "3");
	imprimirArvore(entrevistas);
}

//void testePodcast() {
//	printf("ENTREVISTAS\n");
//	Arvore *diretores = construirArvore(&validadorEntrevista, &imprimirEntrevista);
//	inserirArvore(diretores, criarEntrevista("fury road", "14-05-2015", 150, "george miller", "diretor"));
//	inserirArvore(diretores, criarEntrevista("matrix", "31-03-1999", 136, "lana wachowski", "diretor"));
//	inserirArvore(diretores, criarEntrevista("lord of the rings", "19-12-2001", 178, "peter jackson", "diretor"));
//	inserirArvore(diretores, criarEntrevista("star wars", "25-05-1977", 121, "george lucas", "diretor"));
//	inserirArvore(diretores, criarEntrevista("the godfather", "24-03-1972", 175, "francis ford coppola", "diretor"));
//	imprimirArvore(diretores);
//	
//	Arvore *animacao = construirArvore(&validadorEntrevista, &imprimirEntrevista);
//	inserirArvore(animacao, criarEntrevista("up", "29-05-2009", 96, "pete docter", "animacao"));
//	inserirArvore(animacao, criarEntrevista("toy story", "22-11-1995", 81, "john lasseter", "animacao"));
//	inserirArvore(animacao, criarEntrevista("finding nemo", "30-05-2003", 100, "andrew stanton", "animacao"));
//	inserirArvore(animacao, criarEntrevista("the lion king", "24-06-1994", 88, "roger allers", "animacao"));
//	inserirArvore(animacao, criarEntrevista("shrek", "18-05-2001", 90, "andrew adamson", "animacao"));
//	imprimirArvore(animacao);
//
//	Arvore *atores = construirArvore(&validadorEntrevista, &imprimirEntrevista);
//	inserirArvore(atores, criarEntrevista("drive", "16-09-2011", 100, "ryan gosling", "ator"));
//	inserirArvore(atores, criarEntrevista("the dark knight", "18-07-2008", 152, "heath ledger", "ator"));
//	inserirArvore(atores, criarEntrevista("avengers", "04-05-2012", 143, "robert downey jr.", "ator"));
//	inserirArvore(atores, criarEntrevista("the shawshank redemption", "14-10-1994", 142, "morgan freeman", "ator"));
//	inserirArvore(atores, criarEntrevista("cidade de deus", "30-08-2002", 130, "alexandre rodrigues", "ator"));
//	imprimirArvore(atores);
//
//	Arvore *escritores = construirArvore(&validadorEntrevista, &imprimirEntrevista);
//	inserirArvore(escritores, criarEntrevista("the lord of the rings", "19-12-2001", 178, "j.r.r. tolkien", "escritor"));
//	inserirArvore(escritores, criarEntrevista("harry potter", "16-11-2001", 152, "j.k. rowling", "escritor"));
//	inserirArvore(escritores, criarEntrevista("dune", "14-12-1984", 137, "frank herbert", "escritor"));
//	inserirArvore(escritores, criarEntrevista("the shining", "13-06-1980", 146, "stephen king", "escritor"));
//	inserirArvore(escritores, criarEntrevista("monalisa overdrive", "01-06-1988", 100, "william gibson", "escritor"));
//	imprimirArvore(escritores);
//
//	Arvore *professores = construirArvore(&validadorEntrevista, &imprimirEntrevista);
//	inserirArvore(professores, criarEntrevista("albert einstein", "14-03-1879", 76, "albert einstein", "professor"));
//	inserirArvore(professores, criarEntrevista("richard feynman", "11-05-1918", 69, "richard feynman", "professor"));
//	inserirArvore(professores, criarEntrevista("carl sagan", "09-11-1934", 62, "carl sagan", "professor"));
//	inserirArvore(professores, criarEntrevista("neil degrasse tyson", "05-10-1958", 61, "neil degrasse tyson", "professor"));
//	inserirArvore(professores, criarEntrevista("stephen hawking", "08-01-1942", 76, "stephen hawking", "professor"));
//	imprimirArvore(professores);
//	
//	printf("\n\nTEMAS\n");
//	Arvore *cinema = construirArvore(&validadorTema, &imprimirTema);
//	inserirArvore(cinema, criarTema("filmes", diretores));
//	inserirArvore(cinema, criarTema("documentarios", animacao));
//	inserirArvore(cinema, criarTema("series", atores));
//	imprimirArvore(cinema);
//
//	Arvore *literatura = construirArvore(&validadorTema, &imprimirTema);
//	inserirArvore(literatura, criarTema("fantasia", escritores));
//	inserirArvore(literatura, criarTema("ficcao cientifica", professores));
//	imprimirArvore(literatura);
//	
//	printf("\n\nPODCASTS\n");
//	Arvore *podcast = construirArvore(&validadorPodcast, &imprimirPodcast);
//	inserirArvore(podcast, criarPodcast("podpah", "igor cavalari", cinema));
//	inserirArvore(podcast, criarPodcast("nerdcast", "azaghal", literatura));
//	imprimirArvore(podcast);
//	
//	printf("\n\nPLATAFORMAS\n");
//	Plataforma *youtube = criarPlataforma("youtube", podcast);
//	imprimirPlataforma(youtube);
//}

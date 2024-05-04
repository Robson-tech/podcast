#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teste.h"
#include "binaria/arvore.h"
#include "modelos/plataforma.h"
#include "modelos/podcast.h"
#include "modelos/tema.h"
#include "modelos/entrevista.h"
#include "interface/menu.h"

void teste() {
	testeInterface();
}

void testeInterface() {
	Plataforma *plataformas = NULL;
	Arvore *podcasts = NULL;
	Arvore *temas = NULL;
	Arvore *entrevistas = NULL;
	
	entrevistas = construirArvore(&getChaveEntrevista, 1, &imprimirEntrevista);
	inserirArvore(entrevistas, criarEntrevista("fury road", "14-05-2015", 150, "george miller", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("matrix", "31-03-1999", 136, "lana wachowski", "diretora"));
	inserirArvore(entrevistas, criarEntrevista("lord of the rings", "19-12-2001", 178, "peter jackson", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("star wars", "25-05-1977", 121, "george lucas", "diretor"));
	inserirArvore(entrevistas, criarEntrevista("the godfather", "24-03-1972", 175, "francis ford coppola", "diretor"));
//	imprimirArvore(entrevistas);
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

	menu(plataformas, &buscarArvore, &imprimirArvore, &inserirArvore, &construirArvore, &removerArvore);
//	menu(plataformas, &buscarArvore, &imprimirArvore, &inserirArvore);
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

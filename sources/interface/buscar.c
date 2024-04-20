#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buscar.h"
#include "../modelos/plataforma.h"
#include "../binaria/arvore.h"

Plataforma* buscarInterfacePlataforma(Plataforma *plataformas) {
	Plataforma *busca;
	char nome[100];
	
	if(plataformas) {
		do {
			printf("Plataforma: ");
			scanf("%s", nome);
		} while((busca = buscarPlataforma(plataformas, nome)) == NULL);
	} else
		printf("Nenhuma Plataforma foi cadastradas ainda\n");
}

Podcast* buscarInterfacePodcast(Podcast *podcasts) {
	
}

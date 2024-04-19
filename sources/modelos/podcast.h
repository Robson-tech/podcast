#ifndef PODCAST_H_INCLUDED
#define PODCAST_H_INCLUDED
#include "../binaria/arvore.h"

typedef struct podcast Podcast;

int validadorPodcast(void *estrutura1, void *estrutura2);
Podcast* criarPodcast(char *nome, char *entrevistador, Arvore *temas);
void imprimirPodcast(void *estrutura);

#endif

#ifndef PODCAST_H_INCLUDED
#define PODCAST_H_INCLUDED
#include "../binaria/arvore.h"

typedef struct podcast Podcast;

Podcast* criarPodcast(char *nome, char *entrevistador, Arvore *temas);
void* getChavePodcast(void *estrutura);
void imprimirPodcast(void *estrutura);

#endif

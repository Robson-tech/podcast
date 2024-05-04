#ifndef PODCAST_H_INCLUDED
#define PODCAST_H_INCLUDED

typedef struct podcast Podcast;

Podcast* criarPodcast(char *nome, char *entrevistador, void *temas);
void* getChavePodcast(void *estrutura);
void* getTemas(Podcast *podcast);
void* setTemas(Podcast *podcast, void *estrutura);
void imprimirPodcast(void *estrutura);

#endif

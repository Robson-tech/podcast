#ifndef PLATAFORMA_H_INCLUDED
#define PLATAFORMA_H_INCLUDED

typedef struct plataforma Plataforma;

Plataforma* criarPlataforma(char *nome, void *podcasts);
void* getPodcasts(Plataforma *plataforma);
void setPodcasts(Plataforma *plataforma, void *estrutura);
Plataforma* buscarPlataforma(Plataforma *lista, char *nome);
void inserirPlataforma(Plataforma **lista, Plataforma *nova);
void removerPlataforma(Plataforma **lista, char *nome);
void imprimirPlataforma(Plataforma *plataforma);
void imprimirListaPlataforma(Plataforma *lista);

#endif

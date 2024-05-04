#ifndef REMOVER_H_INCLUDED
#define REMOVER_H_INCLUDED
#include "../modelos/plataforma.h"
#include "../modelos/podcast.h"
#include "../modelos/tema.h"
#include "../modelos/entrevista.h"

void menuRemover(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*remover)(void*, void*));
void opcoesRemover();
void removerInterfacePlataforma(Plataforma **plataformas);
void removerInterfacePodcast(void *podcasts, void* (*buscar)(void*, void*), void (*remover)(void*, void*));
void removerInterfaceTema(void *temas, void* (*buscar)(void*, void*), void (*remover)(void*, void*));
void removerInterfaceEntrevista(void *entrevistas, void* (*buscar)(void*, void*), void (*remover)(void*, void*));

#endif

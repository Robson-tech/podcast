#ifndef BUSCAR_H_INCLUDED
#define BUSCAR_H_INCLUDED
#include "../modelos/plataforma.h"
#include "../modelos/podcast.h"
#include "../modelos/tema.h"
#include "../modelos/entrevista.h"

void menuBuscar(Plataforma *plataformas, void* (*buscar)(void*, void*));
void opcoesBuscar();
Plataforma* buscarInterfacePlataforma(Plataforma *plataformas);
Podcast* buscarInterfacePodcast(void *podcasts, void* (*buscar)(void*, void*));
Tema* buscarInterfaceTema(void *temas, void* (*buscar)(void*, void*));
Entrevista* buscarInterfaceEntrevista(void *entrevistas, void* (*buscar)(void*, void*));

#endif

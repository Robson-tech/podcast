#ifndef BUSCAR_H_INCLUDED
#define BUSCAR_H_INCLUDED
#include "../modelos/plataforma.h"
#include "../modelos/podcast.h"
#include "../modelos/tema.h"
#include "../modelos/entrevista.h"

Plataforma* buscarInterfacePlataforma(Plataforma *plataformas);
Podcast* buscarInterfacePodcast(Podcast *podcasts);
Tema* buscarInterfaceTema(Tema *temas);
Entrevista* buscarInterfaceEntrevista(Entrevista *entrevistas);

#endif

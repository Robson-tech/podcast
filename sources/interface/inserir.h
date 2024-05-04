#ifndef INSERIR_H_INCLUDED
#define INSERIR_H_INCLUDED
#include "../modelos/plataforma.h"
#include "../modelos/podcast.h"
#include "../modelos/tema.h"
#include "../modelos/entrevista.h"

void opcoesInserir();
void menuInserir(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*inserir)(void*, void*), void* (*criar)(void*(*)(void*), int, void(*)(void*)));
Podcast* inserirPodcast(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*inserir)(void*, void*), void* (*criar)(void*(*)(void*), int, void(*)(void*)));
Tema* inserirTema(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*inserir)(void*, void*), void* (*criar)(void*(*)(void*), int, void(*)(void*)));
Entrevista* inserirEntrevista(Plataforma **plataformas, void* (*buscar)(void*, void*), void (*inserir)(void*, void*), void* (*criar)(void*(*)(void*), int, void(*)(void*)));
Plataforma* formularioPlataforma(void* (*criar)(void*(*)(void*), int, void(*)(void*)));
Podcast* formularioPodcast(void* (*criar)(void*(*)(void*), int, void(*)(void*)));
Tema* formularioTema(void* (*criar)(void*(*)(void*), int, void(*)(void*)));
Entrevista* formularioEntrevista();

#endif

#ifndef TEMA_H_INCLUDED
#define TEMA_H_INCLUDED

typedef struct tema Tema;

Tema* criarTema(char *tipo, void *entrevistas);
void* getChaveTema(void *estrutura);
void *getEntrevistas(Tema *tema);
void *setEntrevistas(Tema *tema, void *estrutura);
void imprimirTema(void *estrutura);

#endif

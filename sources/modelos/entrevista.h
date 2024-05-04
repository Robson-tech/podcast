#ifndef ENTREVISTA_H_INCLUDED
#define ENTREVISTA_H_INCLUDED

typedef struct entrevista Entrevista;

Entrevista* criarEntrevista(char *titulo, char *data, int duracao, char *entrevistado, char *especialidade);
void* getChaveEntrevista(void *estrutura);
void imprimirEntrevista(void *estrutura);

#endif

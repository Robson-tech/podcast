#ifndef ENTREVISTA_H_INCLUDED
#define ENTREVISTA_H_INCLUDED

typedef struct entrevista Entrevista;

void* getChaveEntrevista(void *estrutura);
Entrevista* criarEntrevista(char *titulo, char *data, int duracao, char *entrevistado, char *especialidade);
void imprimirEntrevista(void *estrutura);

#endif

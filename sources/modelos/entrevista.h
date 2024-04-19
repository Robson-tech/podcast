#ifndef ENTREVISTA_H_INCLUDED
#define ENTREVISTA_H_INCLUDED

typedef struct entrevista Entrevista;

int validadorEntrevista(void *estrutura1, void *estrutura2);
Entrevista* criarEntrevista(char *titulo, char *data, int duracao, char *entrevistado, char *especialidade);
void imprimirEntrevista(void *estrutura);

#endif

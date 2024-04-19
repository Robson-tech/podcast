#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

typedef struct comando Comando;

Comando* criarComando(char *nome, char *descricao, int num_params, void (*funcao)(int, ...), Comando *subcomandos);
Comando* buscarComando(Comando *lista, char *nome);
void inserirComando(Comando **lista, Comando *novo);
int executarComando(Comando *comando, int num_params, ...);

#endif

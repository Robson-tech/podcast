#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED

void teste();
char* geradorStrings(const int tam, const int itr);
char **gerarListaStrings(const int tamLista, const int tamText);
void destruirListaStrings(char **lista, const int tamLista);
void testeTempoInsercaoBinaria(const int qntd, const int tamText);
void testeTempoBuscaBinaria(const int qntd, const int tamText, const int numBuscas);
void testeTempoInsercaoAVL(const int qntd, const int tamText);
void testeTempoBuscaAVL(const int qntd, const int tamText, const int numBuscas);
void testeAVL();
void testeInterface();
void testeRemocaoLista();
void testeRemocaoArvore();
void testePodcast();

#endif

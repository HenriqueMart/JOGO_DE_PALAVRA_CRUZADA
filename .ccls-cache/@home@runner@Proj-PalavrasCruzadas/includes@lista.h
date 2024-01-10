#ifndef LISTA_H
#define LISTA_H
#define MAX_TAMANHO_PALAVRA 30
#define MAX_TAMANHO_DICA 50

//Arquivo ListaDinEncad.h

struct Palavra {

char palavra[MAX_TAMANHO_PALAVRA];
char dica[MAX_TAMANHO_DICA];
struct Palavra* proxima;

int marcarConcluida; //Variavel para marcar palavra como encontrada

};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct Palavras al);
int insere_lista_inicio(Lista* li, struct Palavras al);
int insere_lista_ordenada(Lista* li, struct Palavras al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);
int consulta_lista_mat(Lista* li, int mat, struct Palavras *al);
int consulta_lista_pos(Lista* li, int pos, struct Palavras *al);






#endif
#ifndef ARVORE_H
#define ARVORE_H


typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin *raiz, struct Palavra palavra);
int remove_ArvBin(ArvBin *raiz, struct Palavra palavra);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, struct Palavra palavra);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);






#endif
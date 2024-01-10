#ifndef PROJETO_H
#define PROJETO_H

#include "stdio.h"

//ESCOLHA LIVRE
#define MAX_TAMANHO_PALAVRA 20
#define MAX_TAMANHO_DICA 20
#define LINHAS 8
#define COLUNAS 8

//STRUCT PALAVRA
struct Palavra {

char palavra[MAX_TAMANHO_PALAVRA];
char dica[MAX_TAMANHO_DICA];
struct Palavra* proxima;

int marcarConcluida; //Variavel para marcar palavra como encontrada
char procurarNaArvore[MAX_TAMANHO_PALAVRA];

};

//STRUCT DA ARVORE
struct NoArvore {
char letra;
struct Palavra palavra; 
struct Palavra dica;
struct NoArvore* esquerda;
struct NoArvore* direita;
struct Palavra* palavraAssociada; 
// Referência para a palavra associada à letra
};

//STRUCT DO JOGADOR
struct Jogador {
    struct NoArvore* raizArvore;
};

//LISTA

typedef struct elemento* Lista;

//ARVORE

typedef struct NoArvore* ArvBin;

//Menu durante a partida
int MENU(ArvBin raiz, Lista encontrados, int numPalavras, int palavrasEncontradas, int tentativa, Lista* li, int nivel);

//FUNCOES PRINCIPAIS (Fornecidas pelo professor)
void criarEDistribuirPalavras(struct Jogador* jogadores, int numJogadores);

struct NoArvore* criarNo(char letra);

struct NoArvore* adicionarPalavraNaArvore(struct NoArvore** raiz, struct Palavra* palavra);

void iniciarlizargrade(char grade[][COLUNAS]);

void exibirgrade(char grade[][COLUNAS]);

void jogarPalavraNaGrade(char palavra[], char grade[][COLUNAS], int palavraencontrada);

struct Palavra* buscarPalavrasNaArvore(struct NoArvore* raiz, char* palavra, int numPalavras);

void iniciarJogoPalavrasCruzadas(ArvBin *av, struct Palavra *palavras, char grade[LINHAS][COLUNAS], int numPalavras, int palavrasEncontradas, int tentativa, int nivel); 

void mostrarEstadoAtual(struct NoArvore* raiz, struct Jogador* jogadore, struct Palavra* palavras);

void escolherPalavras(ArvBin *av, struct Palavra *palavras, char grade[LINHAS][COLUNAS], int numPalavras, int * carregado, int palavraecontrada);

void credito();

void salvarRecursivo(ArvBin no, FILE* arquivo);

int salvarEstadoAtual(ArvBin raiz, int numPalavras, const char* nomeArquivo, int palavrasEncontradas, int tentativa, int nivel);

int carregarEstadoSalvo(ArvBin* raiz, struct Palavra *palavras, int * numPalavras, const char* nomeArquivo, int *palavrasEncontradas, int *tentativa, Lista *encontrada, int *nivel);

int salvarEncontrados(Lista encontrados, const char *nomeArquivo2);
int carregarEncontrados(Lista* encontrados, const char *nomeArquivo2, char grade[LINHAS][COLUNAS], int palavrasEncontradas);



//Funcoes extras

void mostrarLista(struct Palavra* palavras);

//LISTA

Lista* cria_lista();
int insere_lista_ordenada(Lista* li, struct Palavra palavras);
void imprime_lista(Lista* li);
int procurar_lista(Lista* encontrado, char procurarNaArvore[]);
void libera_lista(Lista* li);

//ARVORE

ArvBin* cria_ArvBin();
int insere_ArvBin(ArvBin *raiz, struct Palavra palavra);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
char *consulta_ArvBin(ArvBin *raiz, struct Palavra *palavra);
struct NoArvore* remove_atual(struct NoArvore* atual);
int remove_ArvBin(ArvBin *raiz, char procurarNaArvore[]);
void libera_NO(struct NoArvore* no);
void libera_ArvBin(ArvBin* raiz);

#endif
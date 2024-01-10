#ifndef PROJETO_H
#define PROJETO_H

//ESCOLHA LIVRE
#define MAX_TAMANHO_PALAVRA 20
#define MAX_TAMANHO_DICA 50

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
int MENU(int tentativa, Lista* li);

//FUNCOES PRINCIPAIS (Fornecidas pelo professor)
void criarEDistribuirPalavras(struct Jogador* jogadores, int numJogadores);

struct NoArvore* criarNo(char letra);

struct NoArvore* adicionarPalavraNaArvore(struct NoArvore** raiz, struct Palavra* palavra);

void jogarPalavraNaGrade(struct NoArvore* raiz, struct Palavra* palavra, int linha, int coluna, char direcao);

struct Palavra* buscarPalavrasNaArvore(struct NoArvore* raiz, char* palavra, int numPalavras);

void iniciarJogoPalavrasCruzadas(ArvBin* av, struct Palavra* palavras, int numPalavras);

void mostrarEstadoAtual(struct NoArvore* raiz, struct Jogador* jogadore, struct Palavra* palavras);

void salvarEstadoAtual(struct Jogador* jogadores, int numJogadores, const char* nomeArquivo);

void carregarEstadoSalvo(struct Jogador* jogadores, int numJogadores, const char* nomeArquivo);



//Funcoes extras

void mostrarLista(struct Palavra* palavras, int numPalavras);

//LISTA

Lista* cria_lista();
int insere_lista_ordenada(Lista* li, struct Palavra palavras);
void imprime_lista(Lista* li);
int procurar_lista(Lista* encontrado, char procurarNaArvore[]);

//ARVORE

ArvBin* cria_ArvBin();
int insere_ArvBin(ArvBin *raiz, struct Palavra palavra);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
char *consulta_ArvBin(ArvBin *raiz, struct Palavra *palavra);

#endif
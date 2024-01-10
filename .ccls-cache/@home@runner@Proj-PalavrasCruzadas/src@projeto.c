#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/Projeto.h"



/* Pode nao ser usado, ja que o jogo é individual
void criarEDistribuirPalavras(struct Jogador* jogadores, int numJogadores){

}*/

//FUNCAO ANTIGA DE CRIARNO, NAO ESTA SENDO USADA
struct NoArvore* criarNo(char letra){


  struct NoArvore* novoNo = (struct NoArvore*)malloc(sizeof(struct NoArvore));

  novoNo->letra = letra;
  novoNo->direita = NULL;
  novoNo->esquerda = NULL;
  novoNo->palavraAssociada = NULL;
  return novoNo;

}

int  MENU(int tentativa, Lista* li){
  int menu = 3;
  do{
  system("clear");
  printf("\t\tMENU\t\t\n");
  printf("1 - VOLTAR PARA O MENU INICIAL\n");
  printf("2 - SALVAR PROGRESSO DO JOGO\n");
  printf("3 - VOLTAR A JOGAR\n");
  printf("QUAL VOCÊ DESEJA: ");
    scanf("%d", &menu);

  switch(menu){
    case 1:
      return 0;
    break;
    case 2:
      //salvarEstadoAtual(tentativa, palavras);
    break;
    case 3:
      return;
    default:
      printf("ERRO, DIGITE NOVAMENTE...\n");
  }

  }while(menu != 3);
}
//FUNCAO ANTIGA DE ADICIONAR NA ARVORE, FUNCAO USADA AGORA È A de INSERE BIN
struct NoArvore* adicionarPalavraNaArvore(struct NoArvore** raiz, struct Palavra* palavra){
  
  if(*raiz == NULL){
    *raiz = criarNo(palavra->palavra[0]);
    (*raiz)->palavraAssociada = palavra;
  }else{
    if(palavra->palavra[0] < (*raiz)->letra){
      adicionarPalavraNaArvore(&(*raiz)->esquerda, palavra);
    }else if(palavra->palavra[0] > (*raiz)->letra){
      adicionarPalavraNaArvore(&(*raiz)->direita, palavra);
    }
  }
  
  return *raiz;
}

void jogarPalavraNaGrade(struct NoArvore* raiz, struct Palavra* palavra, int linha, int coluna, char direcao){

  
}

struct Palavra* buscarPalavrasNaArvore(struct NoArvore* raiz, char* palavra, int numPalavras){

  if(raiz == NULL){
    return NULL;
  }

  for(int i = 0; i < numPalavras; i++){
    char primeiraLetra = palavra[i];
  if(primeiraLetra < raiz->letra){
    return buscarPalavrasNaArvore(raiz->esquerda, palavra, numPalavras);
  }else if(primeiraLetra > raiz->letra){
    return buscarPalavrasNaArvore(raiz->direita, palavra, numPalavras);
  }else{
    return raiz->palavraAssociada;
    }
  }
  
}

void iniciarJogoPalavrasCruzadas(ArvBin* av, struct Palavra* palavras, int numPalavras) {
      int palavrasEncontradas = 0, tentativa = 0;
      char menu[1] = "M";
      char procurarNaArvore[MAX_TAMANHO_PALAVRA];
      Lista* encontrado = cria_lista();
      ArvBin* jogoPalavras = cria_ArvBin();
      jogoPalavras = av;
  
      if(encontrado == NULL){
        printf("ERRO, ao criar palavra encontrada!\n");
      }
      printf("\nATENÇÂO: As palavras precisa está em MAIUSCULA!\n");
      printf("Digite a palavra conformer a dica dada para cada palavra!\n");
      printf("ENTER para continuar...\n");
      getchar();
      getchar();
      system("clear");
      while (palavrasEncontradas < numPalavras) {
        printf("\t\t%d RODADA...\nENTER para continuar...", tentativa+1);
        getchar();
        system("clear");
        printf("\t\tJogo Palavras Cruzadas\n");


          if (numPalavras != 0) {
              printf("\n\t%d PALAVRAS ESCONDIDAS | TENTATIVA REALIZADA %d\n\n", numPalavras - palavrasEncontradas, tentativa);
            
          } else {
              printf("Todas as palavras foram encontradas!\n");
              break;
          }


          mostrarLista(palavras, numPalavras);

          struct Palavra* rodada = palavras;

          int encontrouPalavra = 0;

          while (rodada != NULL) {
              if (!rodada->marcarConcluida) {
                  encontrouPalavra = 1;  // Há palavras não marcadas
                  break;
              }
              rodada = rodada->proxima;
          }

          if (!encontrouPalavra) {
              printf("Todas as palavras foram encontradas!\n");
              break;
          }


          printf("\n\t\tDIGITE 'M' para entrar no MENU\n");
          printf("Digite a palavra: ");
          scanf("%s", procurarNaArvore);

          if (!strcmp(procurarNaArvore, menu)){
            if(MENU(tentativa, encontrado)){
              return;
            }
          }else{
            
        struct Palavra palavraEncontrada;
        strcpy(palavraEncontrada.palavra, procurarNaArvore); // Copia de um para outro
      char* dicaEncontrada = consulta_ArvBin(jogoPalavras, &palavraEncontrada);

          //ESSA FUNCAO IRA ENCONTRAR SE A PALAVRA FOI ADICIONADA NA LISTA DE PALAVRAS ENCONTRADAS
          if(procurar_lista(encontrado, procurarNaArvore)){
            printf("Palavra %s já foi encontrada!\n", procurarNaArvore);
          }
            
        if (dicaEncontrada != NULL) {
            printf("Palavra encontrada: %s, Dica: %s, ", palavraEncontrada.palavra, dicaEncontrada); // Troquei a struct para a qual chamamos no início e resolveu o problema
            palavrasEncontradas++;
            tentativa ++;
            if(insere_lista_ordenada(encontrado,  palavraEncontrada)){
              printf("Essa palavra foi guardada!\n");
            }
        } else {
            printf("A palavra '%s' não está nas Palavras Cruzadas.\n", procurarNaArvore);
          tentativa ++;
        }
        getchar();
      }
    }
  
    printf("Todas as palavras foram encontradas!\n");
}

void mostrarEstadoAtual(struct NoArvore* raiz, struct Jogador* jogadores, struct Palavra* palavras){

  printf("Arvore: \n\n");
  //FUNCAO QUE MOSTRA A ARVORE
  if(raiz != NULL && raiz->palavraAssociada != NULL){
    // Imprime a palavra associada ao nó
    printf("Letra: %c, Palavra: %s, Dica: %s\n", raiz->letra, raiz->palavraAssociada->palavra, raiz->palavraAssociada->dica);

    // Chama recursivamente para a subárvore esquerda e direita
    mostrarEstadoAtual(raiz->esquerda, jogadores, palavras);
    mostrarEstadoAtual(raiz->direita, jogadores, palavras);
  }
  
}

void salvarEstadoAtual(struct Jogador* jogadores, int numJogadores, const char* nomeArquivo){

  
}

void carregarEstadoSalvo(struct Jogador* jogadores, int numJogadores, const char* nomeArquivo){

  
}





//Funcao que mostre so as palavras da lista, sem arvore
void mostrarLista(struct Palavra* palavras, int numPalavras){

  struct Palavra *mostrar = palavras;
    printf("Dicas:\n");
    for(int i = 0; i < numPalavras; i++){
        printf("%d - %s\n", i+1, mostrar[i].dica);
        printf("\n");   
    }
}




//LISTA

struct elemento{
    struct Palavra dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

int insere_lista_ordenada(Lista* li, struct Palavra al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.palavra < al.dica){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("Palavra: %s\n",no->dados.palavra);
        printf("Dica: %s\n",no->dados.dica);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

int procurar_lista(Lista* encontrado, char procurarNaArvore[]){
  Elem* procurar = *encontrado;

  while(procurar != NULL){
    if(strcmp(procurar->dados.palavra, procurarNaArvore) == 0){
      return 1;
    }
    procurar = procurar->prox;
  }
  return 0;
}


//ARVORE

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}


int insere_ArvBin(ArvBin *raiz, struct Palavra palavra) {
    if (raiz == NULL) {
        return 0;
    }

    struct NoArvore *novo;
    novo = (struct NoArvore *)malloc(sizeof(struct NoArvore));

    if (novo == NULL)
        return 0;

    // Alocar espaço para a palavra e copiar o conteúdo
    novo->palavraAssociada = (struct Palavra *)malloc(sizeof(struct Palavra));
    if (novo->palavraAssociada == NULL) {
        free(novo);
        return 0;
    }
    strcpy(novo->palavraAssociada->palavra, palavra.palavra);
    strcpy(novo->palavraAssociada->dica, palavra.dica);

    novo->direita = NULL;
    novo->esquerda = NULL;

    if (*raiz == NULL)
        *raiz = novo;
    else {
        struct NoArvore *atual = *raiz;
        struct NoArvore *ant = NULL;

        while (atual != NULL) {
            ant = atual;

            // Comparação de palavras (usando strcmp)
            int comp = strcmp(palavra.palavra, atual->palavraAssociada->palavra);

            if (comp == 0) {
                free(novo->palavraAssociada);
                free(novo);
                return 0; // elemento já existe
            }

            if (comp > 0)
                atual = atual->direita;
            else
                atual = atual->esquerda;
        }

        // Comparação de palavras (usando strcmp)
        int comp = strcmp(palavra.palavra, ant->palavraAssociada->palavra);

        if (comp > 0)
            ant->direita = novo;
        else
            ant->esquerda = novo;
    }

    return 1;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%s\n", (*raiz)->palavraAssociada->palavra);
        preOrdem_ArvBin(&((*raiz)->esquerda));
        preOrdem_ArvBin(&((*raiz)->direita));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esquerda));
        printf("%s\n", (*raiz)->palavraAssociada->palavra);
        printf("%s\n", (*raiz)->palavraAssociada->dica);
        emOrdem_ArvBin(&((*raiz)->direita));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esquerda));
        posOrdem_ArvBin(&((*raiz)->direita));
        printf("%s\n", (*raiz)->palavraAssociada->palavra);
    }
}


char* consulta_ArvBin(ArvBin *raiz, struct Palavra *palavra) {
    if (raiz == NULL)
        return NULL;

    struct NoArvore *atual = *raiz;
    while (atual != NULL) {
        int cmp = strcmp(palavra->palavra, atual->palavraAssociada->palavra);
        if (cmp == 0) {
            // Palavra encontrada, retorne a dica
            return atual->palavraAssociada->dica;
        } else if (cmp > 0) {
            atual = atual->direita;
        } else {
            atual = atual->esquerda;
        }
    }
    return NULL; // palavra não encontrada
}
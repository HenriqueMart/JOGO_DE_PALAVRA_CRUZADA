#include "../includes/Projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//MENU QUE È USADO NO DECORRER DO JOGO
int MENU(ArvBin raiz, Lista encontrados, int numPalavras, int palavrasEncontradas, int tentativa,
         Lista *li, int nivel) {
  int menu = 3;
  char nomeArquivo[] = "data/jogoAtual.txt";
  char nomeArquivo2[] = "data/palavEncontradas.txt";
  system("clear");
  do {

    printf("\t\t▂▂╱▔▔▔▔▔MENU▔▔▔▔▔╲\n");
    printf("\t\t╲▂ 1 - SAIR DO JOGO\n");
    printf("\t\t┈┈▏2 - SALVAR PROGRESSO DO JOGO\n");
    printf("\t\t┈┈▏3 - VOLTAR A JOGAR\n");
    printf("\t\t┈┈╲▂▂▂▂▂▂▂▂▂▂▂▂╱\n\n");

    printf("QUAL VOCÊ DESEJA: ");
    scanf("%d", &menu);

    switch (menu) {
    case 1:
      system("clear");
      printf("Jogo Finalizado. Jogue Novamente!");
      exit(0);
      break;
    case 2:
      // salvarEstadoAtual(tentativa, palavras);
      if (salvarEstadoAtual(raiz, numPalavras, nomeArquivo, palavrasEncontradas, tentativa, nivel) && salvarEncontrados(encontrados, nomeArquivo2)) {
        system("clear");
        printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
        printf("\t\tJogo salvo com sucesso!\n");
        printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
      } else {
        printf("Erro ao salvar o jogo!\n");
      }
      break;
    case 3:
      return 0;
      break;
    default:
      printf("ERRO, DIGITE NOVAMENTE...\n");
    }

  } while (menu != 3);
}

//INICIALIZA A GRADE PARA EVITAR LIXO DE MEMORIA
void iniciarlizargrade(char grade[][COLUNAS]){
  int linha = 8, coluna = 8;

  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      grade[i][j] = '\0';
    }
  }
}

//EXIBE A GRADE COM AS PALAVRAS DA LISTA
void exibirgrade(char grade[][COLUNAS]){
  int linha = 8, coluna = 8;

  printf("\n");
  printf("\t\t    ");
  for (int j = 0; j < coluna; j++) {
    printf("%2d ", j);
  }
  printf("\n");
  for (int i = 0; i < linha; i++) {
    printf("\t\t%2d | ", i);
    for (int j = 0; j < coluna; j++) {
      printf("%c  ", grade[i][j]);
    }
    printf("\n");
  }
}

//FUNCAO QUE JOGA AS PALAVRAS QUE FORAM ENCONTRADAS NA GRADE
void jogarPalavraNaGrade(char palavra[], char grade[][COLUNAS], int palavraencontrada){
  int tamanhodapalavra = strlen(palavra);
  for (int i = 0; i < tamanhodapalavra; i++) {
      
      grade[palavraencontrada][i] = palavra[i];
  }
  return;
}

//FUNCAO PRINCIPAL QUE INICIA O JOGO DE PALAVRAS CRUZADAS
void iniciarJogoPalavrasCruzadas(ArvBin *av, struct Palavra *palavras, char grade[LINHAS][COLUNAS],  int numPalavras, int palavrasEncontradas, int tentativa, int nivel) {
  // numPalavras estava recebendo 1 elemento a mais, entao tirei 1
  numPalavras = numPalavras - 1;
  char menu[1] = "M";

  char procurarNaArvore[MAX_TAMANHO_PALAVRA];
  Lista *encontrado = cria_lista();


  if (encontrado == NULL) {
    printf("ERRO, ao criar lista de palavra encontrada!\n");
  }
  
  printf("\nATENÇÂO: As palavras precisa está em MAIUSCULA!\n");
  printf("Digite a palavra conformer a dica dada para cada palavra!\n");
  printf("ENTER para continuar...\n");
  getchar();
  getchar();
  system("clear");
  
  while (palavrasEncontradas < numPalavras) {
    printf("\t\t%d RODADA...\nENTER para continuar...", tentativa + 1);
    getchar();
    system("clear");
    printf("\t\t           ┈┈╭━━━━━╮┈\n");
    printf("\t\t           ┈╭┻━━┳╮┈┃┈\n");
    printf("\t\t  Jogo     ┈┃▆┈▆┃┃┈┃┈\n");
    printf("\t\t  Palavras ┈╰┳━━┻╯┈┃┈\n");
    printf("\t\t  Cruzadas ┈┈┣┳┳┳╮┈┃┈\n");
    printf("\t\t           ┈┈┣┻┻┻╯┈┃┈\n");

    if (numPalavras != 0) {
      printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
      printf("\n\t\t%d PALAVRAS ESCONDIDAS | TENTATIVA REALIZADA %d\n\n", numPalavras - palavrasEncontradas, tentativa);
      printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");

    } else {
      printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
      printf("\t\tTodas as palavras foram encontradas!\n");
      printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
      break;
    }
    
    exibirgrade(grade);
    
    printf("\n\t\tDicas:\n");
    emOrdem_ArvBin(av);
    printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
    printf("\n\t\tDIGITE 'M' para entrar no MENU\n");
    printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
    printf("\t\tDigite a palavra: ");
    scanf("%s", procurarNaArvore);

    if (!strcmp(procurarNaArvore, menu)) {
      // Voltar para o menu inicial
      if (MENU(*av, *encontrado, numPalavras, palavrasEncontradas, tentativa, encontrado, nivel)) {
        return;
      }
    } else {

      struct Palavra palavraEncontrada;
      strcpy(palavraEncontrada.palavra,
             procurarNaArvore); // Copia de um para outro
      char *dicaEncontrada = consulta_ArvBin(av, &palavraEncontrada);

      // ESSA FUNCAO IRA ENCONTRAR SE A PALAVRA FOI ADICIONADA NA LISTA DE
      // PALAVRAS ENCONTRADAS

      if (dicaEncontrada != NULL &&
          procurar_lista(encontrado, procurarNaArvore) != 1) {
          
          jogarPalavraNaGrade(procurarNaArvore, grade, palavrasEncontradas);
        printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
        printf("Palavra encontrada: %s, Dica: %s, ", palavraEncontrada.palavra,
                 dicaEncontrada); // Troquei a struct para a qual chamamos no início
                                  
          palavrasEncontradas++;
          tentativa++;
          
        if (insere_lista_ordenada(encontrado, palavraEncontrada)) {
          printf("Essa palavra foi guardada!\n");
         
        }
        printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
        remove_ArvBin(av, procurarNaArvore);
      } else {
        printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
        printf("A palavra '%s' não está nas Palavras Cruzadas.\n",
               procurarNaArvore);
        printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
        tentativa++;
      }
      getchar();
      getchar();
    }
  }
  system("clear");
  printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
  printf("\t\tTodas as palavras foram encontradas!\n");
  printf("\t\tTOTAL DE TENTATIVA %d\n", palavrasEncontradas);
  printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
  exibirgrade(grade);

}

//FUNCAO QUE ESCOLHE A DIFICULDADE, AS DICAS FICAM MAIS DIFICEIS
void escolherPalavras(ArvBin *av, struct Palavra *palavras, char grade[LINHAS][COLUNAS], int numPalavras, int *carregado, int palavraecontrada) {
  int  contador = 0, opcao = 0, i = 0;
  if (*carregado == 0){ 
    if(*carregado == 0){
      iniciarlizargrade(grade);
    }
    
    system("clear");
    printf("\n\t\t╰╮╰╮╰╮╰╮╰╮╰╮\n");
    printf("\t\t╭━━━━━━━━━━━╮\n");
    printf("\t\t╰━━━━━━━━━━━╯\n");
    printf("\t\t┃1 - Facil  ┣━╮\n");
    printf("\t\t┃2 - Medio  ┃ ┃\n");
    printf("\t\t┃3 - Dificil┣━╯\n\n");
    printf("Qual dificuldade você deseja jogar?\n\n");
    scanf("%d", &(*carregado));
  }
  switch (*carregado) {
  case 1:

    palavras = (struct Palavra[]){
        {"CASA", "C_S_"},     {"QUARTO", "Q__RT_"}, {"ESCOLA", "E__OLA"},
        {"BRASIL", "__A_IL"}, {"AVIAO", "_VIA_"},   {""},
    };
   
    while (palavras[contador].palavra[0] != '\0') {
      contador++;
    }
    numPalavras = contador;

    for (int i = 0; i < numPalavras; i++) {
   
      insere_ArvBin(av, palavras[i]);
    }

    break;
  case 2:
    numPalavras = 0;
    palavras = (struct Palavra[]){
        {"CASA", "C_S_"},     {"QUARTO", "Q___T_"}, {"ESCOLA", "E__O__"},
        {"BRASIL", "__A__L"}, {"AVIAO", "A_I__"},   {""},
    };

    while (palavras[contador].palavra[0] != '\0') {
      contador++;
    }
    numPalavras = contador;

    for (int i = 0; i < numPalavras; i++) {
      insere_ArvBin(av, palavras[i]);
    }

    break;
  case 3:
    numPalavras = 0;
    palavras = (struct Palavra[]){
        {"CASA", "__S_"},     {"QUARTO", "____T_"}, {"ESCOLA", "___O__"},
        {"BRASIL", "__A___"}, {"AVIAO", "A____"},   {""},
    };

    while (palavras[contador].palavra[0] != '\0') {
      contador++;
    }
    numPalavras = contador;

    for (int i = 0; i < numPalavras; i++) {
      insere_ArvBin(av, palavras[i]);
    }

    break;
  default:
    printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
    printf("\t\tEscolha uma das opçoes\n");
    printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
    break;
  }
  
}

void credito(){
  system("clear");
  printf("\n\tDESENVOLVEDORES DO PROJETO:\n");
  printf("\n\tJosé Henrique Martins B. Silva");

  printf("\n\tGabriel Barauna De Souza\n");
}

//SALVANDO AS PALAVRAS QUE NAO FORAM ENCONTRADAS
void salvarRecursivo(ArvBin no, FILE *arquivo) {
  if (no != NULL) {
    fprintf(arquivo, "%s %s\n", no->palavraAssociada->palavra, no->palavraAssociada->dica);
    salvarRecursivo(no->esquerda, arquivo);
    salvarRecursivo(no->direita, arquivo);
  }
}

int salvarEstadoAtual(ArvBin raiz, int numPalavras, const char *nomeArquivo, int palavrasEncontradas, int tentativa, int nivel) {

  FILE *arquivo = fopen(nomeArquivo, "w");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
    return 0;
  }
  fprintf(arquivo, "%d %d %d %d\n", numPalavras+1, palavrasEncontradas, tentativa, nivel);
  if (raiz != NULL) {
    fprintf(arquivo, "%s %s\n", raiz->palavraAssociada->palavra, raiz->palavraAssociada->dica);
    salvarRecursivo(raiz->esquerda, arquivo);
    salvarRecursivo(raiz->direita, arquivo);
  }

  fclose(arquivo);

  return 1;
}

//CARREGANDO AS PALAVRAS QUE NAO FORAM ENCONTRADAS
int carregarEstadoSalvo(ArvBin* raiz, struct Palavra *palavras, int *numPalavras, const char *nomeArquivo, int *palavrasEncontradas, int *tentativa, Lista *encontrada, int *nivel) {
  FILE *arquivo = fopen(nomeArquivo, "r");
  char Palavrafile[MAX_TAMANHO_PALAVRA];
  char Dicafile[MAX_TAMANHO_DICA];
  system("clear");
  printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
  printf("\t\tPROGRESSO DO JOGO ANTERIOR!\n");
  printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
    return 0;
  }

  fscanf(arquivo, "%d %d %d %d\n", numPalavras, palavrasEncontradas, tentativa, nivel);

  
  for (int i = 0; i < *numPalavras && fscanf(arquivo, "%s %s\n", Palavrafile, Dicafile) == 2; i++) {

      struct Palavra palavrasalva;
      strcpy(palavrasalva.palavra,
         Palavrafile); // Copiar a palavra para a instância da struct
      strcpy(palavrasalva.dica,
         Dicafile);

      
      insere_ArvBin(raiz, palavrasalva);
    
  }

  printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
  //emOrdem_ArvBin(raiz);
  printf("\t\tTotal de palavra encontrada %d\n\tSuas tentativa %d\n", *palavrasEncontradas, *tentativa);
  printf("\t\t\t\t▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n");
  fclose(arquivo);

  
  return 1;
}


// FUNCOES DE LISTA

struct elemento {
  struct Palavra dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

Lista *cria_lista() {
  Lista *li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL)
    *li = NULL;
  return li;
}

int insere_lista_ordenada(Lista *li, struct Palavra al) {
  if (li == NULL)
    return 0;
  Elem *no = (Elem *)malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = al;
  if ((*li) == NULL) { // lista vazia: insere início
    no->prox = NULL;
    *li = no;
    return 1;
  } else {
    Elem *ant, *atual = *li;
    while (atual != NULL && atual->dados.palavra < al.dica) {
      ant = atual;
      atual = atual->prox;
    }
    if (atual == *li) { // insere início
      no->prox = (*li);
      *li = no;
    } else {
      no->prox = atual;
      ant->prox = no;
    }
    return 1;
  }
}

void imprime_lista(Lista *li) {
  if (li == NULL)
    return;
  Elem *no = *li;
  while (no != NULL) {
    printf("Palavra: %s\n", no->dados.palavra);
    printf("Dica: %s\n", no->dados.dica);
    printf("-------------------------------\n");

    no = no->prox;
  }
}

int procurar_lista(Lista *encontrado, char procurarNaArvore[]) {
  Elem *procurar = *encontrado;

  while (procurar != NULL) {
    if (strcmp(procurar->dados.palavra, procurarNaArvore) == 0) {
      return 1;
    }
    procurar = procurar->prox;
  }
  return 0;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

//SALVANDO E CARREGANDO AS PALAVRAS DA LISTA QUE JA FORAM ENCONTRADAS PARA A GRADE 
int salvarEncontrados(Lista encontrado, const char *nomeArquivo2) {

  FILE *arquivo = fopen(nomeArquivo2, "w");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", nomeArquivo2);
    return 0;
  }

  Elem *no = encontrado;
  while (no != NULL) {
    fprintf(arquivo, "%s\n", no->dados.palavra);
    no = no->prox;
  }

  fclose(arquivo);

  return 1;
}

int carregarEncontrados(Lista* encontrados, const char *nomeArquivo2, char grade[LINHAS][COLUNAS], int palavrasEncontradas) {

  FILE *arquivo = fopen(nomeArquivo2, "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", nomeArquivo2);
    return 0;
  }

  iniciarlizargrade(grade);
  palavrasEncontradas = 0;

  char palavraFile[20];

  
  struct Palavra palavraCarregada;
  while (fscanf(arquivo, "%s\n", palavraCarregada.palavra) == 1) {
    // Insere a palavra na lista
    insere_lista_ordenada(encontrados, palavraCarregada);
    strcpy(palavraFile, palavraCarregada.palavra);
    jogarPalavraNaGrade(palavraFile, grade, palavrasEncontradas);
    palavrasEncontradas++;
  }
  fclose(arquivo);

  return 1;
}

// FUNCOES DA ARVORE

ArvBin *cria_ArvBin() {
  ArvBin *raiz = (ArvBin *)malloc(sizeof(ArvBin));
  if (raiz != NULL)
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

void preOrdem_ArvBin(ArvBin *raiz) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    printf("\t\t%s\n", (*raiz)->palavraAssociada->palavra);
    preOrdem_ArvBin(&((*raiz)->esquerda));
    preOrdem_ArvBin(&((*raiz)->direita));
  }
}

void emOrdem_ArvBin(ArvBin *raiz) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    emOrdem_ArvBin(&((*raiz)->esquerda));
    printf("\t\t%s\n", (*raiz)->palavraAssociada->dica);
    emOrdem_ArvBin(&((*raiz)->direita));
  }
}

void posOrdem_ArvBin(ArvBin *raiz) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    posOrdem_ArvBin(&((*raiz)->esquerda));
    posOrdem_ArvBin(&((*raiz)->direita));
    printf("\t\t%s\n", (*raiz)->palavraAssociada->dica);
  }
}

char *consulta_ArvBin(ArvBin *raiz, struct Palavra *palavra) {
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

struct NoArvore *remove_atual(struct NoArvore *atual) {
  struct NoArvore *no1, *no2;
  if (atual->esquerda == NULL) {
    no2 = atual->direita;
    free(atual);
    return no2;
  }
  no1 = atual;
  no2 = atual->esquerda;
  while (no2->direita != NULL) {
    no1 = no2;
    no2 = no2->direita;
  }
  // no2 é o nó anterior a r na ordem e-r-d
  // no1 é o pai de no2
  if (no1 != atual) {
    no1->direita = no2->esquerda;
    no2->esquerda = atual->esquerda;
  }
  no2->direita = atual->direita;
  free(atual);
  return no2;
}

int remove_ArvBin(ArvBin *raiz, char procurarNaArvore[]) {
  if (raiz == NULL)
    return 0;

  struct NoArvore *ant = NULL;
  struct NoArvore *atual = *raiz;

  while (atual != NULL) {
    if (strcmp(procurarNaArvore, atual->palavraAssociada->palavra) == 0) {
      if (atual == *raiz)
        *raiz = remove_atual(atual);
      else {
        if (ant->direita == atual)
          ant->direita = remove_atual(atual);
        else
          ant->esquerda = remove_atual(atual);
      }
      return 1;
    }

    int comp = strcmp(procurarNaArvore, atual->palavraAssociada->palavra);

    ant = atual;
    if (comp > 0)
      atual = atual->direita;
    else
      atual = atual->esquerda;
  }
  return 0;
}

void libera_NO(struct NoArvore* no){
    if(no == NULL)
        return;
    libera_NO(no->esquerda);
    libera_NO(no->direita);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

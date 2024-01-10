#include "../includes/Projeto.h"

int main(void) {
  //Variáveis principais
  int opcao, palavrasEncontradas = 0, tentativa = 0, numPalavras = 6, nivel = 0;
  int numJogadores = 1;
  char nomeArquivo[] = "data/jogoAtual.txt";
  char nomeArquivo2[] = "data/palavEncontradas.txt";

  char procurarNaArvore[MAX_TAMANHO_PALAVRA];
  char grade[LINHAS][COLUNAS];
  iniciarlizargrade(grade);

  struct NoArvore *raiz = NULL;
  ArvBin *av = cria_ArvBin();
  Lista *li = cria_lista();
  struct Jogador jogadores[numJogadores];

  struct Palavra palavras[] = {
      {"\0", "\0"},
  };
  //Cruzamento de palavra sequência: ESCOLA, QUARTO, CASA e BRASIL. Forma CASA


  do {

    system("clear");
    printf("\t\t█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
    printf("\t\t█---╔╦╗╔╗╦╔╗╔╗╔╦╗╔╗╗--█\n");
    printf("\t\t█---    PALAVRAS    --█\n");
    printf("\t\t█---    CRUZADAS    --█\n");
    printf("\t\t█---╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝--█\n");
    printf("\t\t█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n\n");

    printf("\t\t▂▂╱▔▔▔▔▔▔▔▔▔▔▔▔╲\n");
    printf("\t\t╲▂ 1 - Novo Jogo\n");
    printf("\t\t┈┈▏2 - Continuar Jogo\n");
    printf("\t\t┈┈▏3 - Créditos\n");
    printf("\t\t┈┈▏0 - Sair\n");
    printf("\t\t┈┈╲▂▂▂▂▂▂▂▂▂▂▂▂╱\n\n");

    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      nivel = 0;
      palavrasEncontradas = 0;
      tentativa = 0;
      escolherPalavras(av, palavras, grade, numPalavras, &nivel, palavrasEncontradas);

      iniciarJogoPalavrasCruzadas(av, palavras, grade, numPalavras, palavrasEncontradas, tentativa, nivel);
      break;
    case 2:
      if(carregarEstadoSalvo(av, palavras, &numPalavras, nomeArquivo, &palavrasEncontradas, &tentativa, li, &nivel) && carregarEncontrados(li, nomeArquivo2, grade, palavrasEncontradas)){ 

        iniciarJogoPalavrasCruzadas(av, palavras, grade, numPalavras,
        palavrasEncontradas, tentativa, nivel);
      }
      
      break;
    case 3:
      credito();
      break;
    default:
      printf("Saindo...\n");
      break;
    }

    if (opcao != 0) {
      printf("\n\n\t\tPressione Enter para Retornar ao Menu de Opções\n");
      getchar();
      getchar();
    }

  } while (opcao != 0);


  return 0;
}
#include <stdio.h>
#include <string.h>

// função para ler os dados da carta
void lerCarta(char *nomeCidade, char *codigoCarta, char *estado,
              unsigned long int *populacao, float *area, float *PIB,
              int *pontosTuristicos)
{
  printf("Estado: ");
  scanf(" %c", estado);

  printf("Codigo: ");
  scanf(" %s", codigoCarta);
  getchar();

  printf("Nome da Cidade: ");
  fgets(nomeCidade, 30, stdin);
  nomeCidade[strcspn(nomeCidade, "\n")] = '\0';

  printf("Populacao: ");
  scanf("%lu", populacao);

  printf("Área: ");
  scanf("%f", area);

  printf("PIB: ");
  scanf("%f", PIB);

  printf("Numero de Pontos Turisticos: ");
  scanf("%d", pontosTuristicos);
}

// função para exibir os dados fornecidos das cartas
void exibirCarta(char estado, char *codigoCarta, char *nomeCidade, int quantidadePontosTuristicos,
                 unsigned long int populacao, float area, float PIB, float PIBPerCapita,
                 float densidadePopulacional, float superPoder)
{
  printf("\nEstado: %c\n", estado);
  printf("Codigo: %s\n", codigoCarta);
  printf("Nome da Cidade: %s\n", nomeCidade);
  printf("Populacao: %lu\n", populacao);
  printf("Area: %.2f km²\n", area);
  printf("PIB: %.2f bilhoes de reais\n", PIB);
  printf("Numero de Pontos Turisticos: %d\n", quantidadePontosTuristicos);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional);
  printf("PIB per Capita: %.2f reais\n", PIBPerCapita);
}

// função para calcular métricas derivadas
void calcularMetricas(unsigned long int populacao, float area, float PIB,
                      int pontosTuristicos, float *densidade,
                      float *pibPerCapita, float *superPoder)
{
  *densidade = populacao / area;
  *pibPerCapita = (PIB * 1000000000.0f) / populacao;
  *superPoder = pontosTuristicos + populacao + area + PIB + *pibPerCapita + (1 / *densidade);
}

// função para exibir o menu com as opções de comparações
void exibirMenuOpcoesComparacoes()
{
  printf("\nQual atributo deseja comparar entre as cartas?\n");

  printf("1 - Populacao\n");
  printf("2 - Area\n");
  printf("3 - PIB\n");
  printf("4 - Numero de pontos turisticos\n");
  printf("5 - Densidade demográfica\n");
}

// função para comparar a população
void compararPopulacao(unsigned long int populacao_C1, unsigned long int populacao_C2,
                       char *nomeCidade_C1, char *nomeCidade_C2)
{
  printf("\n\nComparação de cartas (Atributo: População):\n\n");

  if (populacao_C1 > populacao_C2)
  {
    printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade_C1);
  }
  else if (populacao_C1 < populacao_C2)
  {
    printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade_C2);
  }
  else
  {
    printf("Empate\n");
  }

  printf("Carta 1: %s: %lu\n", nomeCidade_C1, populacao_C1);
  printf("Carta 2: %s: %lu\n", nomeCidade_C2, populacao_C2);
}

// função para comparar a area
void compararArea(float area_C1, float area_C2, char *nomeCidade_C1, char *nomeCidade_C2)
{
  printf("\n\nComparação de cartas (Atributo: Area):\n\n");

  if (area_C1 > area_C2)
  {
    printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade_C1);
  }
  else if (area_C1 < area_C2)
  {
    printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade_C2);
  }
  else
  {
    printf("Empate\n");
  }

  printf("Carta 1: %s: %.2f km²\n", nomeCidade_C1, area_C1);
  printf("Carta 2: %s: %.2f km²\n", nomeCidade_C2, area_C2);
}

// função para comparar o pib
void compararPIB(float PIB_C1, float PIB_C2, char *nomeCidade_C1, char *nomeCidade_C2)
{
  printf("\n\nComparação de cartas (Atributo: PIB):\n\n");

  if (PIB_C1 > PIB_C2)
  {
    printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade_C1);
  }
  else if (PIB_C1 < PIB_C2)
  {
    printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade_C2);
  }
  else
  {
    printf("Empate\n");
  }

  printf("Carta 1: %s: %.2f bilhões\n", nomeCidade_C1, PIB_C1);
  printf("Carta 2: %s: %.2f bilhões\n", nomeCidade_C2, PIB_C2);
}

// função para comparar os pontos turisticos
void compararPontosTuristicos(int pontos_C1, int pontos_C2, char *nomeCidade_C1, char *nomeCidade_C2)
{
  printf("\n\nComparação de cartas (Atributo: Pontos Turísticos):\n\n");

  if (pontos_C1 > pontos_C2)
  {
    printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade_C1);
  }
  else if (pontos_C1 < pontos_C2)
  {
    printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade_C2);
  }
  else
  {
    printf("Empate\n");
  }

  printf("Carta 1: %s: %d\n", nomeCidade_C1, pontos_C1);
  printf("Carta 2: %s: %d\n", nomeCidade_C2, pontos_C2);
}

// função para comparar a densidade
void compararDensidade(float densidade_C1, float densidade_C2, char *nomeCidade_C1, char *nomeCidade_C2)
{
  printf("\n\nComparação de cartas (Atributo: Densidade Demográfica):\n\n");

  if (densidade_C1 < densidade_C2)
  {
    printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade_C1);
  }
  else if (densidade_C1 > densidade_C2)
  {
    printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade_C2);
  }
  else
  {
    printf("Empate\n");
  }

  printf("Carta 1: %s: %.2f hab/km²\n", nomeCidade_C1, densidade_C1);
  printf("Carta 2: %s: %.2f hab/km²\n", nomeCidade_C2, densidade_C2);
}

int main()
{
  // Variaveis da carta 1 -----------------------------------
  char estado_C1, codigoCarta_C1[4], nomeCidade_C1[30];
  int quantidadePontosTuristicos_C1;
  unsigned long int populacao_C1;
  float area_C1, PIB_C1, PIBPerCapita_C1, densidadePopulacional_C1, superPoder_C1;

  // Variaveis da carta 2 -----------------------------------
  char estado_C2, codigoCarta_C2[4], nomeCidade_C2[30];
  int quantidadePontosTuristicos_C2;
  unsigned long int populacao_C2;
  float area_C2, PIB_C2, PIBPerCapita_C2, densidadePopulacional_C2, superPoder_C2;

  // Solicitar dados da carta 1 -----------------------------------
  printf("Carta 1:\n");
  lerCarta(nomeCidade_C1, codigoCarta_C1, &estado_C1, &populacao_C1, &area_C1, &PIB_C1, &quantidadePontosTuristicos_C1);

  calcularMetricas(populacao_C1, area_C1, PIB_C1, quantidadePontosTuristicos_C1,
                   &densidadePopulacional_C1, &PIBPerCapita_C1, &superPoder_C1);

  // Solicitar dados da carta 2 -----------------------------------
  printf("\nCarta 2:\n");
  lerCarta(nomeCidade_C2, codigoCarta_C2, &estado_C2, &populacao_C2, &area_C2, &PIB_C2, &quantidadePontosTuristicos_C2);

  // As areas e populacao nao podem ser zero
  if (area_C1 == 0 || area_C2 == 0 || populacao_C1 == 0 || populacao_C2 == 0)
  {
    printf("Erro: Área e população não podem ser zero!\n");
    return 1;
  }

  calcularMetricas(populacao_C2, area_C2, PIB_C2, quantidadePontosTuristicos_C2,
                   &densidadePopulacional_C2, &PIBPerCapita_C2, &superPoder_C2);

  // Exibir dados da carta 1
  printf("\nCarta 1:\n");
  exibirCarta(estado_C1, codigoCarta_C1, nomeCidade_C1, quantidadePontosTuristicos_C1,
              populacao_C1, area_C1, PIB_C1, PIBPerCapita_C1,
              densidadePopulacional_C1, superPoder_C1);

  // Exibir dados da carta 2
  printf("\nCarta 2\n");
  exibirCarta(estado_C2, codigoCarta_C2, nomeCidade_C2, quantidadePontosTuristicos_C2,
              populacao_C2, area_C2, PIB_C2, PIBPerCapita_C2,
              densidadePopulacional_C2, superPoder_C2);

  // Exibir comparacao das cartas
  printf("\nComparacao de Cartas:\n");

  printf("\nPopulacao: Carta %s venceu (%d)\n", populacao_C1 > populacao_C2 ? "1" : "2", populacao_C1 > populacao_C2 ? 1 : 0);
  printf("Area: Carta %s venceu (%d)\n", area_C1 > area_C2 ? "1" : "2", area_C1 > area_C2 ? 1 : 0);
  printf("PIB: Carta %s venceu (%d)\n", PIB_C1 > PIB_C2 ? "1" : "2", PIB_C1 > PIB_C2 ? 1 : 0);
  printf("Pontos turisticos: Carta %s venceu (%d)\n", quantidadePontosTuristicos_C1 > quantidadePontosTuristicos_C2 ? "1" : "2", quantidadePontosTuristicos_C1 > quantidadePontosTuristicos_C2 ? 1 : 0);
  printf("Densidade Populacional: Carta %s venceu (%d)\n", densidadePopulacional_C1 < densidadePopulacional_C2 ? "1" : "2", densidadePopulacional_C1 < densidadePopulacional_C2 ? 1 : 0);
  printf("PIB per Capita: Carta %s venceu (%d)\n", PIBPerCapita_C1 > PIBPerCapita_C2 ? "1" : "2", PIBPerCapita_C1 > PIBPerCapita_C2 ? 1 : 0);
  printf("Super Poder: Carta %s venceu (%d)\n", superPoder_C1 > superPoder_C2 ? "1" : "2", superPoder_C1 > superPoder_C2 ? 1 : 0);

  // comparando populacao entre as cartas

  // Menu
  exibirMenuOpcoesComparacoes();

  int opcao;

  printf("\nInforme a opcao que deseja comparar: ");
  scanf("%d", &opcao);
  getchar();

  switch (opcao)
  {
  case 1:
    compararPopulacao(populacao_C1, populacao_C2, nomeCidade_C1, nomeCidade_C2);
    break;
  case 2:
    compararArea(area_C1, area_C2, nomeCidade_C1, nomeCidade_C2);
    break;
  case 3:
    compararPIB(PIB_C1, PIB_C2, nomeCidade_C1, nomeCidade_C2);
    break;
  case 4:
    compararPontosTuristicos(quantidadePontosTuristicos_C1, quantidadePontosTuristicos_C2,
                             nomeCidade_C1, nomeCidade_C2);
    break;
  case 5:
    compararDensidade(densidadePopulacional_C1, densidadePopulacional_C2,
                      nomeCidade_C1, nomeCidade_C2);
    break;
  default:
    printf("Opção inválida!\n");
    break;
  }

  return 0;
}

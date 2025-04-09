#include <stdio.h>
#include <string.h>

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

void calcularMetricas(unsigned long int populacao, float area, float PIB,
                      int pontosTuristicos, float *densidade,
                      float *pibPerCapita, float *superPoder)
{
  *densidade = populacao / area;
  *pibPerCapita = (PIB * 1000000000.0f) / populacao;
  *superPoder = pontosTuristicos + populacao + area + PIB + *pibPerCapita + (1 / *densidade);
}

void exibirMenuOpcoesComparacoes(int atributoSelecionado)
{
  printf("\nEscolha o %s atributo para comparar:\n", atributoSelecionado == -1 ? "primeiro" : "segundo");

  if (atributoSelecionado != 1)
    printf("1 - Populacao\n");
  if (atributoSelecionado != 2)
    printf("2 - Area\n");
  if (atributoSelecionado != 3)
    printf("3 - PIB\n");
  if (atributoSelecionado != 4)
    printf("4 - Pontos Turisticos\n");
  if (atributoSelecionado != 5)
    printf("5 - Densidade Demografica\n");
}

float obterValorAtributo(int opcao, unsigned long int populacao, float area, float PIB,
                         int pontos, float densidade)
{
  switch (opcao)
  {
  case 1:
    return (float)populacao;
  case 2:
    return area;
  case 3:
    return PIB;
  case 4:
    return (float)pontos;
  case 5:
    return densidade;
  default:
    return 0;
  }
}

int main()
{
  // Dados Carta 1
  char estado_C1, codigoCarta_C1[4], nomeCidade_C1[30];
  int pontos_C1;
  unsigned long int pop_C1;
  float area_C1, PIB_C1, PIBpc_C1, dens_C1, super_C1;

  // Dados Carta 2
  char estado_C2, codigoCarta_C2[4], nomeCidade_C2[30];
  int pontos_C2;
  unsigned long int pop_C2;
  float area_C2, PIB_C2, PIBpc_C2, dens_C2, super_C2;

  // Entrada das cartas
  printf("Carta 1:\n");
  lerCarta(nomeCidade_C1, codigoCarta_C1, &estado_C1, &pop_C1, &area_C1, &PIB_C1, &pontos_C1);
  calcularMetricas(pop_C1, area_C1, PIB_C1, pontos_C1, &dens_C1, &PIBpc_C1, &super_C1);

  printf("\nCarta 2:\n");
  lerCarta(nomeCidade_C2, codigoCarta_C2, &estado_C2, &pop_C2, &area_C2, &PIB_C2, &pontos_C2);
  calcularMetricas(pop_C2, area_C2, PIB_C2, pontos_C2, &dens_C2, &PIBpc_C2, &super_C2);

  // Exibição
  printf("\nCarta 1:\n");
  exibirCarta(estado_C1, codigoCarta_C1, nomeCidade_C1, pontos_C1, pop_C1, area_C1, PIB_C1, PIBpc_C1, dens_C1, super_C1);

  printf("\nCarta 2:\n");
  exibirCarta(estado_C2, codigoCarta_C2, nomeCidade_C2, pontos_C2, pop_C2, area_C2, PIB_C2, PIBpc_C2, dens_C2, super_C2);

  // Escolha dos atributos
  int atributo1 = -1, atributo2 = -1;

  exibirMenuOpcoesComparacoes(-1);
  printf("Digite o primeiro atributo: ");

  scanf("%d", &atributo1);

  exibirMenuOpcoesComparacoes(atributo1);
  printf("Digite o segundo atributo: ");
  scanf("%d", &atributo2);

  // Valores dos atributos
  float valor1_C1 = obterValorAtributo(atributo1, pop_C1, area_C1, PIB_C1, pontos_C1, dens_C1);
  float valor1_C2 = obterValorAtributo(atributo1, pop_C2, area_C2, PIB_C2, pontos_C2, dens_C2);

  float valor2_C1 = obterValorAtributo(atributo2, pop_C1, area_C1, PIB_C1, pontos_C1, dens_C1);
  float valor2_C2 = obterValorAtributo(atributo2, pop_C2, area_C2, PIB_C2, pontos_C2, dens_C2);

  // Vencedor de cada atributo
  int v1 = (atributo1 == 5) ? (valor1_C1 < valor1_C2 ? 1 : (valor1_C1 > valor1_C2 ? 2 : 0))
                            : (valor1_C1 > valor1_C2 ? 1 : (valor1_C1 < valor1_C2 ? 2 : 0));

  int v2 = (atributo2 == 5) ? (valor2_C1 < valor2_C2 ? 1 : (valor2_C1 > valor2_C2 ? 2 : 0))
                            : (valor2_C1 > valor2_C2 ? 1 : (valor2_C1 < valor2_C2 ? 2 : 0));

  float soma_C1 = valor1_C1 + valor2_C1;
  float soma_C2 = valor1_C2 + valor2_C2;

  int vencedorFinal = (soma_C1 > soma_C2) ? 1 : ((soma_C1 < soma_C2) ? 2 : 0);

  // Resultado
  printf("\n--- Resultado da Comparação ---\n");

  printf("Atributo 1: %s\n", (atributo1 == 1) ? "População" : (atributo1 == 2) ? "Área"
                                                          : (atributo1 == 3)   ? "PIB"
                                                          : (atributo1 == 4)   ? "Pontos Turísticos"
                                                                               : "Densidade");
  printf(" - %s: %.2f\n", nomeCidade_C1, valor1_C1);
  printf(" - %s: %.2f\n", nomeCidade_C2, valor1_C2);
  printf(" > Vencedor: %s\n", v1 == 0 ? "Empate" : (v1 == 1 ? nomeCidade_C1 : nomeCidade_C2));

  printf("Atributo 2: %s\n", (atributo2 == 1) ? "População" : (atributo2 == 2) ? "Área"
                                                          : (atributo2 == 3)   ? "PIB"
                                                          : (atributo2 == 4)   ? "Pontos Turísticos"
                                                                               : "Densidade");
  printf(" - %s: %.2f\n", nomeCidade_C1, valor2_C1);
  printf(" - %s: %.2f\n", nomeCidade_C2, valor2_C2);
  printf(" > Vencedor: %s\n", v2 == 0 ? "Empate" : (v2 == 1 ? nomeCidade_C1 : nomeCidade_C2));

  printf("\nSoma dos atributos:\n");
  printf(" - %s: %.2f\n", nomeCidade_C1, soma_C1);
  printf(" - %s: %.2f\n", nomeCidade_C2, soma_C2);
  printf(" >> Vencedor Final: %s\n", vencedorFinal == 0 ? "Empate!" : (vencedorFinal == 1 ? nomeCidade_C1 : nomeCidade_C2));

  return 0;
}

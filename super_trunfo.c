#include <stdio.h>
#include <string.h>

int main() {
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

  printf("Estado: ");
  scanf(" %c", &estado_C1);
  
  printf("Codigo: ");
  scanf(" %s", &codigoCarta_C1);
  getchar(); // Consumir o \n que restou no buffer

  printf("Nome da Cidade: ");
  fgets(nomeCidade_C1, sizeof(nomeCidade_C1), stdin);
  nomeCidade_C1[strcspn(nomeCidade_C1, "\n")] = '\0'; // encontrar e remover o \n presente na string

  printf("Populacao: ");
  scanf("%lu", &populacao_C1);
  
  printf("Área: ");
  scanf("%f", &area_C1);

  printf("PIB: ");
  scanf("%f", &PIB_C1);

  printf("Numero de Pontos Turisticos: ");
  scanf("%d", &quantidadePontosTuristicos_C1);

  densidadePopulacional_C1 = populacao_C1 / (float) area_C1; // hab/km²
  PIBPerCapita_C1 = (PIB_C1 * 1000000000.0f)  / (float) populacao_C1; // PIB em reais (não bilhões)
  superPoder_C1 = (float) quantidadePontosTuristicos_C1 + (float) populacao_C1 + area_C1 + PIB_C1 + PIBPerCapita_C1 + (1 / densidadePopulacional_C1);

  // Solicitar dados da carta 2 -----------------------------------
  printf("\nCarta 2:\n");

  printf("Estado: ");
  scanf(" %c", &estado_C2);
  
  printf("Codigo: ");
  scanf(" %s", &codigoCarta_C2);
  getchar(); // Consumir o \n que restou no buffer
  
  printf("Nome da Cidade: ");
  fgets(nomeCidade_C2, sizeof(nomeCidade_C2), stdin);
  nomeCidade_C2[strcspn(nomeCidade_C2, "\n")] = '\0'; // encontrar e remover o \n presente na string

  printf("Populacao: ");
  scanf("%lu", &populacao_C2);
  
  printf("Área: ");
  scanf("%f", &area_C2);

  printf("PIB: ");
  scanf("%f", &PIB_C2);

  printf("Numero de Pontos Turisticos: ");
  scanf("%d", &quantidadePontosTuristicos_C2);

  densidadePopulacional_C2 = populacao_C2 / (float) area_C2; // hab/km²
  PIBPerCapita_C2 = (PIB_C2 * 1000000000.0f) / (float) populacao_C2; // PIB em reais (não bilhões)
  superPoder_C2 = (float) quantidadePontosTuristicos_C2 + (float) populacao_C2 + area_C2 + PIB_C2 + PIBPerCapita_C2 + (1 / densidadePopulacional_C2);

  // Exibir dados da carta 1
  printf("\nCarta 1:\n");
  
  printf("\nEstado: %c\n", estado_C1);
  printf("Codigo: %s\n", codigoCarta_C1);
  printf("Nome da Cidade: %s\n", nomeCidade_C1);
  printf("Populacao: %lu\n", populacao_C1);
  printf("Area: %.2f km²\n", area_C1);
  printf("PIB: %.2f bilhoes de reais\n", PIB_C1);
  printf("Numero de Pontos Turisticos: %d\n", quantidadePontosTuristicos_C1);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional_C1);
  printf("PIB per Capita: %.2f reais\n", PIBPerCapita_C1);
  
  // Exibir dados da carta 2
  printf("\nCarta 2\n");
  
  printf("\nEstado: %c\n", estado_C2);
  printf("Codigo: %s\n", codigoCarta_C2);
  printf("Nome da Cidade: %s\n", nomeCidade_C2);
  printf("Populacao: %lu\n", populacao_C2);
  printf("Area: %.2f km²\n", area_C2);
  printf("PIB: %.2f bilhoes de reais\n", PIB_C2);
  printf("Numero de Pontos Turisticos: %d\n", quantidadePontosTuristicos_C2);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional_C2);
  printf("PIB per Capita: %.2f reais\n", PIBPerCapita_C2);
  
  // Exibir comparacao das cartas
  printf("\nComparacao de Cartas:\n");

  printf("\nPopulacao: Carta %s venceu (%d)\n", populacao_C1 > populacao_C2 ? "1" : "2", populacao_C1 > populacao_C2 ? 1 : 0);
  printf("Area: Carta %s venceu (%d)\n", area_C1 > area_C2 ? "1" : "2", area_C1 > area_C2 ? 1 : 0);
  printf("PIB: Carta %s venceu (%d)\n", PIB_C1 > PIB_C2 ? "1" : "2", PIB_C1 > PIB_C2 ? 1 : 0);
  printf("Pontos turisticos: Carta %s venceu (%d)\n", quantidadePontosTuristicos_C1 > quantidadePontosTuristicos_C2 ? "1" : "2", quantidadePontosTuristicos_C1 > quantidadePontosTuristicos_C2 ? 1 : 0);
  printf("Densidade Populacional: Carta %s venceu (%d)\n", densidadePopulacional_C1 < densidadePopulacional_C2 ? "1" : "2", densidadePopulacional_C1 < densidadePopulacional_C2 ? 1 : 0);
  printf("PIB per Capita: Carta %s venceu (%d)\n", PIBPerCapita_C1 > PIBPerCapita_C2 ? "1" : "2", PIBPerCapita_C1 > PIBPerCapita_C2 ? 1 : 0);
  printf("Super Poder: Carta %s venceu (%d)\n", superPoder_C1 > superPoder_C2 ? "1" : "2", superPoder_C1 > superPoder_C2 ? 1 : 0);
  
  return 0;
}


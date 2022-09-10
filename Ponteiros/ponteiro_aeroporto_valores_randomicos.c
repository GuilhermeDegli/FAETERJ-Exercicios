/* Programa que calcula a pontuação de uma pesquisa com números aleatórios feita
 * num aeroporto */

#include <stdlib.h>
#include <time.h>
#define TAM 20
#define PTOS 8

int calculaNota(int vResp[], int vPontuacao[], int *anuladas, int *ptsTotal) {

  (*anuladas) = 0;
  (*ptsTotal) = 0;

  for (int i = 0; i < TAM; i++) {

    if (vResp[i] >= 9 || vResp[i] <= 0) {
      (*anuladas) += 1;

    } else {
      (*ptsTotal) += vPontuacao[vResp[i] - 1];
    }
  }
  return *anuladas;
}
int exibeSatisfacao(int vResp[], int anuladas, int ptsTotal) {

  int i;
  int codEmb = 333;

  printf("\nResultado da entrevista:\n\n");

  for (int i = 0; i < TAM; i++) {
    printf("Pontuação pergunta [%i] : "
           "%d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ",
           i + 1, vResp[i]);
  }
  printf("\n\nCódigo de embarque: %d", codEmb);

  if (anuladas <= 6) {
    printf("\n6 ou menos questões foram anuladas.");

    if (ptsTotal >= 90) {
      printf("\nSatisfação: Muito satisfeito.");
    } else if (ptsTotal >= 75 && ptsTotal <= 89) {
      printf("\nSatisfação: Satisfeito.");
    } else {
      printf("\nSatisfação: Insatisfeito.");
    }

  } else if (anuladas >= 7 && anuladas <= 12) {
    printf("\nEntre 7 e 12 perguntas anuladas.");

    if (ptsTotal >= 90) {
      printf("\nSatisfação: Muito satisfeito");
    } else if (ptsTotal >= 75 && ptsTotal <= 89) {
      printf("\nSatisfação: Satisfeito.");
    } else {
      printf("\nSatisfação: Insatisfeito.");
    }

  } else {
    printf("\nMais de 12 perguntas anuladas.");
    printf("\nSatisfação: Respostas insuficientes.");
  }

  printf("\nPerguntas anuladas: %d", anuladas);
  printf("\nPontuação total: %d", ptsTotal);

  return 0;
}

int main(void) {
  int anuladas;
  int ptsTotal;
  int vResp[TAM];
  int vPontuacao[PTOS] = {1, 3, 3, 3, 4, 6, 6, 10};

  srand(time(NULL));
  for (int i = 0; i < TAM; i++)
    vResp[i] = rand() % 11;

  calculaNota(vResp, vPontuacao, &anuladas, &ptsTotal);
  exibeSatisfacao(vResp, anuladas, ptsTotal);

  return 0;
}
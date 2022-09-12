#include <stdio.h>

float litro(float peso) {

  float LPDia;

  LPDia = (35 * peso) / 1000;
  return LPDia;
}

void mAgua(float LPDia) {

  printf("\n|Quantidade de água em litros: %.2f  L/dia.|\n", LPDia);
}

void repeteAlunos(int fn) {

  int fcont_fn, i;
  float peso, LPDia;

  fcont_fn = 0;

  for (i = 0; fcont_fn < fn; i++) {

    printf("\n\nPeso do aluno (%i) em KG:  ", 1 + i);
    scanf("%f", &peso);

    LPDia = litro(peso);
    mAgua(LPDia);
    fcont_fn += 1;
  }
}

int main(void) {

  int n;
  float LPDia;
  float peso;

  LPDia = litro(peso);

  printf("Número de alunos da turma:\n");
  scanf("%d", &n);
  repeteAlunos(n);
  printf("\n\n---fim---\n\n\n");

  return 0;
}

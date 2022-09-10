#include <stdio.h>

int main(void) {

  int idade, meses;
  float preço, preço1, preço2, preço3, desc1, desc2, desc3;

  printf("\nDigite a quantos meses você é cliente:\n");
  scanf("%d", &meses);

  if (meses >= 30) {

    printf("\nQual a sua idade:\n");
    scanf("%d", &idade);
  }

  printf("\nPreço do produto:\n");
  scanf("%f", &preço);

  if (meses <= 10) {
    printf("\nValor a se pagar: %.2fR$\n", preço);
  }

  else if (meses <= 29) {

    desc1 = (preço * 1.09) - preço;
    preço1 = preço - desc1;

    printf("\nFoi descontado %.2fR$ do valor anterior.\n", desc1);
    printf("\nValor a se pagar agora: %.2fR$\n", preço1);
  }

  else if (meses <= 45) {

    if (idade > 60) {

      desc2 = (preço * 1.17) - preço;
      preço2 = preço - desc2;

    }

    else {
      desc2 = (preço * 1.12) - preço;
      preço2 = preço - desc2;
    }

    printf("\nFoi descontado %.2fR$ do valor anterior.\n", desc2);
    printf("\nValor a se pagar agora: %.2fR$\n", preço2);

  }

  else {

    if (idade > 60) {

      desc3 = (preço * 1.20) - preço;
      preço3 = preço - desc3;

    }

    else {
      desc3 = (preço * 1.15) - preço;
      preço3 = preço - desc3;
    }

    printf("\nFoi descontado %.2fR$ do valor anterior.\n", desc3);
    printf("\nValor a se pagar agora: %.2fR$\n", preço3);
  }
  return 0;
}
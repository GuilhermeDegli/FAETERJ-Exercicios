/* Um programa que diga o preço a se pagar por um vestido com base no tipo do
 * vestido, o metro do tecido e o preço por metros.  */

#include <stdio.h>

int tecidoDaFantasia(int tipoTecido) {
  int t;

  if (tipoTecido == 1) {

    t = 10;
    printf("\n[O tecido é do tipo A, com custo adicional de %dR$/Metro.]", t);
    return t;
  }

  else if (tipoTecido == 2) {

    t = 30;
    printf("\n[O tecido é do tipo B, com custo adicional de %dR$/Metro.]", t);
    return t;
  }

  else {

    t = 50;
    printf("\n[O tecido é do tipo C, com custo adicional de %dR$/Metro.]", t);
    return t;
  }

  return t;
}

int tamanhoDaFantasia(int metrosDeTecido, int preçoMetros) {
  int z, r, t, tipoTecido;

  t = tecidoDaFantasia(tipoTecido);

  z = metrosDeTecido * preçoMetros * t;

  if (z < 300) {
    r = metrosDeTecido * preçoMetros;
    return r;
  }

  else if (z > 300 && z <= 500) {
    r = z - ((z * 1.15) - z);
    printf("\n\nO valor sem desconto é: %dR$", z);

    return r;

  }

  else {
    r = z - ((z * 1.30) - z);
    printf("\n\nO valor sem desconto é: %dR$", z);

    return r;
  }

  return r;
}

int main(void) {
  int preçoMetros, metrosDeTecido, tipoTecido, x, r;

  printf("\nInforme o tipo do "
         "tecido:\n[1]-Theemothee\n[2]-Xibiu\n[3]-Fumabare\n\n\n");
  scanf("%d", &tipoTecido);
  printf("\nInforme o preço do metro do tecido:\n");
  scanf("%d", &preçoMetros);
  printf("\nInforme quantos metros de tecido serão necessários:\n");
  scanf("%d", &metrosDeTecido);

  r = tamanhoDaFantasia(metrosDeTecido, preçoMetros);
  printf("\nO valor a ser pago é: %dR$", r);

  return 0;
}
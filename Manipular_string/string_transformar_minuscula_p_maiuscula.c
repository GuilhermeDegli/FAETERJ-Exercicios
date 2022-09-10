/* Programa que coloca a primeira letra de cada palavra da frase em maiúsculo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int i;
  char frase[20];

  printf("\n\nEscreva qualquer frase: ");
  scanf("%[^\n]", frase);

  for (i = 0; i < strlen(frase); i++) {

    frase[i] |= (1 << 5);
    if (!i || frase[i - 1] == ' ')
      frase[i] &= ~(1 << 5);
  }
  printf("\nFrase corrigida: %s\n", frase);
  return 0;
}
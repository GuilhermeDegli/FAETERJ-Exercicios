/* Programa que marca e conta a quantidade de aparições de letras em um texto
 */

#include <stdio.h>
#include <string.h>
#define TAM 64
#define LET 26

int buscaChar(char v[], int n, char p) {
  int i;
  for (i = 0; i < n; i++) {
    if (v[i] == p)
      return i;
  }
  return -1;
}

int quantidadeDeOcorrencias(char c, char v[]) {
  int i, cont = 0, tam = strlen(v);
  for (i = 0; i < tam; i++) {
    if (v[i] == c)
      cont++;
  }
  return cont;
}

int montaTabela(char frase[], char Letras[], int vQts[]) {
  int i, j, pos, rep, ultpos = 0;

  for (i = 0; frase[i] != '\0'; i++) {
    if (frase[i] >= 'a' && frase[i] <= 'z') {
      rep = buscaChar(Letras, ultpos, frase[i]);
      if (rep != -1)
        vQts[rep]++;
      else {
        Letras[ultpos] = frase[i];
        vQts[ultpos] = 1;
        ultpos++;
      }
    }
  }
  return ultpos;
}

void exibeTabelaFrequencia(int n, char Letras[], int vQts[]) {
  int i;
  printf("\n\nCaractere\tQuantidade de Ocorrencias\n\n");
  for (i = 0; i < n; i++) {
    printf("%c\t\t\t%d\n", Letras[i], vQts[i]);
  }
}

int main(void) {
  char string[TAM];
  int vQts[LET];
  char Letras[LET];
  int qt;
  printf("\nDigite o texto que deseja saber:\n\n");
  scanf(" %[^\n]", string);
  qt = montaTabela(string, Letras, vQts);
  exibeTabelaFrequencia(qt, Letras, vQts);
  return 0;
}
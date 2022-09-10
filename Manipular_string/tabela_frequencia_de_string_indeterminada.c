// Aluno: Guilherme Degliomini Lira
// Turno: Noite
// Turma: A

/*  Programa que faz a pesquisa do nivel de escolaridade de um numero
 * indeterminado de alunos e então cria uma tabela da frequencia dos alunos com a média de idade de casa nivel. */

#include <stdio.h>
#include <string.h>
#define TAM 7

int Dados(char grau[][30], int idade[], int vmaiorIdade[], int idadeMedia[]) {
  int i = 0;
  for (int i = 0; i < 7; i++) {

    idadeMedia[i] = 0;
    vmaiorIdade[i] = 0;
  }

  printf("\nDIGITE o nível de escolaridade\nou DIGITE [Fim] para terminar: ");
  scanf(" %[^\n]", grau[i]);
  while (strcmp(grau[i], "fim") != 0 && i < TAM) {
    printf("\nDIGITE sua idade: ");
    scanf("%d", &idade[i]);
    i++;
    printf(
        "\nDIGITE o nível de escolaridade\nou DIGITE '[Fim] para terminar: ");
    scanf(" %[^\n]", grau[i]);
  }
  return i;
}

int vGrais(char graus[][30], int idadeMedia[], int maiorIdade[]) {

  strcpy(graus[0], "analfabeto");
  strcpy(graus[1], "primeiro grau");
  strcpy(graus[2], "segundo grau");
  strcpy(graus[3], "superior");
  strcpy(graus[4], "mestrado");
  strcpy(graus[5], "doutorado");
  strcpy(graus[6], "outros");

  return 7;
}

int Verificador(char grau[][30], int idade[]) {
  strcpy(grau[0], "analfabeto");
  idade[0] = 40;
  strcpy(grau[1], "segundo grau");
  idade[1] = 30;
  strcpy(grau[2], "primeiro grau");
  idade[2] = 20;
  strcpy(grau[3], "analfabeto");
  idade[3] = 20;
  strcpy(grau[4], "primeiro grau");
  idade[4] = 30;
  return 5;
}

int Ler(int x, char graus[][30], char val[]) {
  int i;
  for (i = 0; i < x; i++) {
    if (strcmp(graus[i], val) == 0)
      return i;
  }
  return -1;
}

void maiorIdade(int x, int y, char graus[][30], char grau[][30], int idade[],
                int idadeMaior[]) {
  int i, pos;
  for (i = 0; i < y; i++) {
    pos = Ler(x, graus, grau[i]);
    if (pos != -1) {
      if (idadeMaior[pos] < idade[i])
        idadeMaior[pos] = idade[i];
    }
  }
}

void calcMedia(int x, int y, char graus[][30], char grau[][30], int idade[],
               int idadeMedia[]) {
  int i, pos, qt[x];
  for (i = 0; i < x; i++)
    qt[i] = 0;
  for (i = 0; i < y; i++) {
    pos = Ler(x, graus, grau[i]);
    if (pos != -1) {
      idadeMedia[pos] += idade[i];
      qt[pos]++;
    }
  }
  for (i = 0; i < x; i++) {
    if (qt[i] > 0)
      idadeMedia[i] = idadeMedia[i] / qt[i];
  }
}

void mostraTabela(char graus[][30], int idadeMedia[], int idadeMaior[]) {
  int i;
  printf("\nNível\t\tEscolaridade\t\t\t  Media\t\t\t  Mais Velho");
  for (i = 0; i < TAM; i++) {
    printf("\n%-6d\t\t%s\t\t%6d\t\t%6d", i + 1, graus[i], idadeMedia[i],
           idadeMaior[i]);
  }
  return;
}

int main(void) {

  printf("\n\nNIVEIS DE GRAU DE ESCOLARIDADE\n\n\n[1] Analfabeto\n[2] Primeiro "
         "Grau\n[3] Segundo Grau\n[4] Superior\n[5] Mestrado\n[6] "
         "Doutorado\n[7] Outros\n\n");

  int i, x, y, idade[TAM], idadeMaior[7];
  int idadeMedia[7];
  char grau[TAM][30], graus[7][30];
  y = Dados(grau, idade, idadeMaior, idadeMedia);
  x = vGrais(graus, idadeMedia, idadeMaior);
  maiorIdade(x, y, graus, grau, idade, idadeMaior);
  calcMedia(x, y, graus, grau, idade, idadeMedia);
  mostraTabela(graus, idadeMedia, idadeMaior);
  return 0;
}
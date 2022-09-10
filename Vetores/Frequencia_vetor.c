/* Informações VETORIZADAS para serem exibidas  */

#include <stdio.h>
#include <string.h>
#define TAM 50
#define CLASS 8

void zeraVetor(int n, int v[]) {
  int i;
  for (i = 0; i < n; i++)
    v[i] = 0;
}

int montaTabela(char curso[][64], int cod_curso[], float rec_med[]) {
  int i;
  strcpy(curso[0], "Informática");
  strcpy(curso[1], "Medicina");
  strcpy(curso[2], "Direito");
  strcpy(curso[3], "Engenharia");
  strcpy(curso[4], "Letras");
  strcpy(curso[5], "Matemática");
  strcpy(curso[6], "Biologia");
  strcpy(curso[7], "Pedagogia");
  for (i = 0; i < CLASS; i++)
    cod_curso[i] = i + 20;
  for (i = 0; i < CLASS; i++)
    rec_med[i] = 0;
  return CLASS;
}

int preencheDados(int matr[], float media[]) {
  int i = 0;
  printf("Digite a matrícula ou '0' para finalizar: ");
  scanf("%d", &matr[i]);
  while (matr[i] != 0 && i < TAM) {
    printf("Digite a média geral: ");
    scanf("%f", &media[i]);
    i++;
    printf("Digite a matrícula ou '0' para finalizar: ");
    scanf("%d", &matr[i]);
  }
  return i;
}

int testeDados(int matr[], float media[]) {
  matr[0] = 22486;
  media[0] = 8.5;
  matr[1] = 20345;
  media[1] = 9.5;
  matr[2] = 25267;
  media[2] = 8.5;
  matr[3] = 19182;
  media[3] = 7.5;
  matr[4] = 20304;
  media[4] = 8.0;
  return 5;
}

int busca(int n, int p, int v[]) {
  int i;
  for (i = 0; i < n; i++) {
    if (v[i] == p)
      return i;
  }
  return -1;
}

int separaMatricula(int *matr, int *num, int *trim, int *seq, int cod_curso[]) {
  int v1, v2, v3;
  *num = (*matr / 1000);
  *trim = (*matr - ((*num) * 1000)) / 100;
  *seq = *matr - (*num) * 1000 - (*trim) * 100;
  v1 = busca(CLASS, *num, cod_curso);
  if ((*trim) >= 1 && (*trim) <= 4)
    v2 = 1;
  else
    v2 = 0;
  if ((*seq) >= 1 && (*seq) <= 90)
    v3 = 1;
  else
    v3 = 0;
  if (v1 == -1 || v2 == 0 || v3 == 0)
    return 0;
  return 1;
}

void verificaRecomendacao(int n, float media[], float rec[]) {
  int i;
  for (i = 0; i < n; i++) {
    if (media[i] > 9)
      rec[i] = 0.3;
    else if (media[i] >= 8)
      rec[i] = 0.1;
    else if (media[i] >= 7)
      rec[i] = 0.05;
    else
      rec[i] = 0;
  }
}

void mostraDados(int n, int val[], int matr[], int num[], float rec[]) {
  int i;
  printf("\nDados dos alunos:");
  printf("\nMatrícula\tCód.Curso\tRecomendação\n");
  for (i = 0; i < n; i++) {
    if (val[i] == 0)
      printf("Matrícula não válida.\n");
    else
      printf("%d\t\t\t%d\t\t\t%.2f%%\n", matr[i], num[i], rec[i] * 100);
  }
}

void calculaMedia(int n, int num[], int cod_curso[], float rec[],
                  float rec_med[]) {
  int i, pos, qt[CLASS];
  zeraVetor(CLASS, qt);
  for (i = 0; i < n; i++) {
    pos = busca(CLASS, num[i], cod_curso);
    if (pos != -1) {
      rec_med[pos] += rec[i];
      qt[pos]++;
    }
  }
  for (i = 0; i < n; i++) {
    if (qt[i] > 0)
      rec_med[i] /= qt[i];
  }
}

void totalizacao(int n, char curso[][64], float rec_med[]) {
  int i;
  printf("\nEstatísticas por curso:");
  printf("\nCurso\t\tRec.Média\n");
  for (i = 0; i < n; i++)
    printf("%s\t\t%.2f%%\n", curso[i], rec_med[i] * 100);
}

int main(void) {
  int i, n, matr[TAM], num[TAM], trim[TAM], seq[TAM], cod_curso[CLASS],
      val[TAM];
  float media[TAM], rec[TAM], rec_med[CLASS];
  char curso[CLASS][64];
  montaTabela(curso, cod_curso, rec_med);
  // n=preencheDados(matr,media);
  n = testeDados(matr, media);
  for (i = 0; i < n; i++)
    val[i] = separaMatricula(&matr[i], &num[i], &trim[i], &seq[i], cod_curso);
  verificaRecomendacao(n, media, rec);
  mostraDados(n, val, matr, num, rec);
  calculaMedia(n, num, cod_curso, rec, rec_med);
  totalizacao(CLASS, curso, rec_med);
  return 0;
}
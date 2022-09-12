#include <stdio.h>
#define TAM 5

int Vetores(int not []) {
  for (int i = 0; i < TAM; i++) {
    printf("Digite a sua RESPOSTA na questão[%d]:  ", i + 1);
    scanf("%d", &not [i]);
  }
  return 0;
}

int Gabarito(int gab[]) {

  for (int i = 0; i < TAM; i++) {
    printf("Digite o GABARITO da questão[%d]:   ", i + 1);
    scanf("%d", &gab[i]);
  }
  return 0;
}

int Corrigir(int vgab[], int vnot[]) {

  int acertos = 0;
  for (int i = 0; i < TAM; i++) {

    while (i < TAM) {

      if (vgab[i] == vnot[i]) {

        acertos += 2;
        printf("\nA resposta da questão [%d] está CORRETA.  ", i+=1);

      }

      else {

        acertos += 0;
        printf("\nA resposta da questão [%d] está INCORRETA.  ", i+=1);
      }
    }
  }

  return acertos;
}

int main(void) {
  int vnot[TAM];
  int vgab[TAM];
  int acertos;
  int nalu;
  int alu = 0;
  int valu=0;
  
  for (alu = 0; alu < nalu; alu++)


  printf("\n\n GABARITO DAS QUESTÕES:\n");
  Gabarito(vgab);

  printf("\nDigite quantos alunos serão avaliados:  ");
  scanf("%d", &nalu); 

  for (alu = 0; alu < nalu; alu++)

    while (alu < nalu) {

      printf("\nRESPOSTA DAS QUESTÕES DO ALUNO %d:\n", alu+=1);
      Vetores(vnot);
      acertos = Corrigir(vgab, vnot);
      printf("\n\nNOTA DO ALUNO %d:\n", alu+1);
      printf("\n%d/10 PONTOS", acertos);
    }
    
  return 0;
}
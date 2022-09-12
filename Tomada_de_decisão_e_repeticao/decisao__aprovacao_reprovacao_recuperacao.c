// Programa para calcular a média entre duas notas e dizer a situação do Aluno

void calcMedia(float nota1, float nota2) {
  

  // int media = nota 1 + nota 2 / 2;

  if ((nota1 + nota2) / 2 > 9.0) {

    printf("\nAPROVADO: com média %.2f.\nVocê ficou com %.2f pontos acima do que o necessário para aprovação.\nGostaria de se tornar monitor ?",
           (nota1 + nota2) / 2, ((nota1 + nota2) / 2 - 6));

  }

  else if ((nota1 + nota2) / 2 == 6.0) {
    printf("\nAPROVADO: com média %.2f.\nVocê ficou exatamente na média.", (nota1 + nota2) / 2);

  }

    else if ((nota1 + nota2) / 2 >= 6.0) {
    printf("\nAPROVADO: com média %.2f.\nVocê ficou com %.2f pontos acima do que o necessário para aprovação.", (nota1 + nota2) / 2, ((nota1 + nota2) / 2 - 6));

  }


  else if ((nota1 + nota2) / 2 >= 4 && (nota1 + nota2) / 2 < 6) {
    printf("\nRECUPERAÇÃO: com média %.2f.\nVoce precisa de %.2f pontos para "
           "ser aprovado.",
           (nota1 + nota2) / 2, (6 - (nota1 + nota2) / 2));
  }

  else {
    printf("\nREPROVADO com média %.2f.\nVocê precisava de mais %.2f pontos para ser aprovado na recuperação.", (nota1 + nota2) / 2, (4 - (nota1 + nota2) / 2) );
  }
}

int main(void) {

  float nota1, nota2;

  printf("\nDigite a nota da AV1:\n");
  scanf("%f", &nota1);
  printf("\nDigite a nota da AV2:\n");
  scanf("%f", &nota2);

  calcMedia(nota1, nota2);

  return 0;
}
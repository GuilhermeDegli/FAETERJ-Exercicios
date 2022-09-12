#include <stdio.h>

void descobre_xy(int *X, int *Y) {

  int ANO;

  if (ANO > 1900 && ANO < 2000) {
    *X = 24;
    *Y = 5;
  } else {
    if (ANO < 2100) {
      *X = 24;
      *Y = 5;
    } else {
      if (ANO < 2199) {
        *X = 24;
        *Y = 6;
      } else {
        *X = 25;
        *Y = 7;
      }
    }
  }
}
int descobre_DataPascoa(int ANO, int *DIA, int *MES) {

  int X, Y;

  descobre_xy(&X, &Y);

  int A = ANO % 19;
  int B = ANO % 4;
  int C = ANO % 7;
  int D = (19 * A + X) % 30;
  int E = (2 * B + 4 * C + 6 * D + Y) % 7;

  if ((D + E) > 9) {

    *DIA = (D + E - 11);
    *MES = 4;

    if ((*MES == 4) && (*DIA == 26)) {
      *DIA = 19;
      return 1;
    }
    if ((*MES == 4) && (*DIA == 25) && (D == 28) && (A > 10)) {
      *DIA = 18;

      return 1;
    }

    return 1;

  } else {

    if ((D + E) <= 9) {

      *DIA = (D + E + 22);
      *MES = 3;

      return 1;
    }

    return 1;
  }
}

int main(void) {

  int X, Y;
  int ANO = 2023, DIA, MES;

  descobre_xy(&X, &Y);
  descobre_DataPascoa(ANO, &DIA, &MES);

  printf("No ano de [%d] a páscoa aconteceu em: %d/0%d/%d", ANO, DIA, MES, ANO);

  return 0;
}
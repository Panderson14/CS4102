/*Patrick Anderson psa5dg 4102 Algorithms HW1*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void changeMaker(int payment);

int main(int argc, char *argv[]) {
  setlocale(LC_NUMERIC, "");
  float  multiplier;
  FILE *input;

  input = fopen(argv[1], "r");
  while (1) {
    fscanf(input, "%f", &multiplier);
    if (multiplier == -1) break;
    printf("$%'.2lf", multiplier);
    multiplier = multiplier - floorf(multiplier);
    changeMaker((int) ((multiplier+0.005)*100));
  }
  fclose(input);
  return 0;
}

void changeMaker(int payment) {
  while(payment - 25 >= 0) {
      printf(" Q");
      payment-=25;
    }
    while(payment - 10 >= 0) {
      printf(" D");
      payment-=10;
    }
    while(payment - 5 >= 0) {
      printf(" N");
      payment-=5;
    }
    while(payment - 1 >= 0) {
      printf(" P");
      payment-=1;
    }
    printf("\n");
}

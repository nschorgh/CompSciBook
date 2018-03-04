#include <math.h>
#include <stdio.h>

int main(void) {
  float x;
  x=sqrt(-1.);

  if (x >= 0) {
    printf("x is positive or zero\n");
  } else {
    printf("x is negative\n");
  }
}

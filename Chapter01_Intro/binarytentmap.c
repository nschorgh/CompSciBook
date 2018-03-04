#include <math.h>
#include <stdio.h>

void dectobin(double x) {
  int i;
  double b=1.,y;
  y=x;
  if (x>1. || x<0.) printf("error\n");
  if (x<1.)
    printf("0.");
  else
    printf("1.");
  for(i=1;i<=52;i++) {
    b=b/2.;
    if (y-b >= 0.) {
      printf("1");
      y = y-b;
    } else {
      printf("0");
    }
  }
}   


int main() {
  int i;
  double x=0.398;
  //x=0.5;
  for(i=1;i<=10;i++) {
    //x=fmod(2.*x,1.);
    dectobin(x);
    //printf(" a \n"); dectobin(1.-x);
    if (x<=0.5)
      x = 2.*x;
    else
      x = 2.*(1.-x);
    printf("\n");
  }
  return 0;
}

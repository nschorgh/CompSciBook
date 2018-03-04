#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* this program is used for figures in chapter 1 */
int main() {
  double r, x, xold;
  int i;
  //for(r=0.;r<=3.1415927;r+=0.0015) {
  //for(r=0.;r<=4.;r+=0.0015) {
  for(r=2.8;r<=4.;r+=0.0005) {  // zoom
    x=0.4;  
    xold=-9.;
    for(i=0;i<=1050;i++) {
      //x=sin(r*x);
      x=r*x*(1.-x);
      //x=r*(1.-fabs(2.*x-1.));
      if (i>=1000 && fabs(x-xold)>1.e-5) { // save on output
	printf("%f %f\n",r,x);
	xold=x;
      }
    }
    printf("\n");
  }
  return 0;
}

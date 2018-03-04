#include <math.h>
#include <stdio.h>

/* this program is used for numbers in chapter 1 */
int main() {
  int i;
  double r=4., x=0.8;

  for(i=0;i<1020;i++) {
    printf("%d %0.3f\n",i,x);
    //x=sin(r*x);   /* sine map */
    x=r*x*(1.-x);   /* logistic map */
    //x=r*(1.-fabs(2.*x-1.));   /* tent map */
  }
  return 0;
}

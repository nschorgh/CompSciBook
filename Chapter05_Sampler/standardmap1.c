#include <math.h>
#include <stdio.h>

/* individual time series for standard map */

int main() {
  int i;
  double pi=3.141592653589793, pi2=2.*pi, T=1.;
  //double K=0., u=0.2,  a=0.1; 
  //double K=5., u=pi2,  a=0.;
  //double K=0.2, u=0., a=2.; 
  double K=0.2, u=1., a=2.; 
  //double K=1.4, u=1., a=0.; 

  for(i=0;i<30;i++) {
    printf("%g  %7.4f %7.4f\n",i*T,u,a);
    a+=u*T;
    a=fmod(a,pi2);
    if (a<0.) a+=pi2;
    u+=K*sin(a);
  }
  return 0;
}

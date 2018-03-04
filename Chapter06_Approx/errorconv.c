#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int N;


double f(int i) {
  double x;
  x=i/(1.*N);
  return sin(2.*x-0.17)+0.3*cos(3.4*x+0.1);
}


int main() {
  const int MAXN=1024*1024*9;
  int i,count;
  double norm,g1,g2,oldnorm=-1.;
  for(N=10;N<MAXN;N*=2) {
    count=0; norm=0.;
    for(i=2;i<N-2;i+=2) {
      g1=(f(i+1)-f(i-1))/2.*N;
      g2=(f(i+2)-f(i-2))/2.*N/2;
      norm+=(g1-g2)*(g1-g2);
      count++;
    }
    if (count) {
      norm=sqrt(norm/count);
      printf("%d %g ",N,norm);
      if (oldnorm>0.) 
         printf("%g\n",oldnorm/norm);
      else
         printf("\n");
      oldnorm=norm;
    }
  }
  return 0;
}

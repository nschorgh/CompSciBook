#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
  const int N = 1000000000;
  int i;
  double a;
  double before,elapsed;

  a = 1.;
  before = clock();
  for(i=0;i<N;i++) a = a+12.1;
  elapsed = (clock()-before)/CLOCKS_PER_SEC;
  printf("%f %f\n",elapsed,a);

  a = 1.;
  before = clock();
  for(i=0;i<N;i++) a=a*1.0000001;
  elapsed = (clock()-before)/CLOCKS_PER_SEC;
  printf("%f %f\n",elapsed,a);

  a = 1e10;
  before = clock();
  for(i=0;i<N;i++) a=a/1.0000001;
  elapsed = (clock()-before)/CLOCKS_PER_SEC;
  printf("%f %g\n",elapsed,a);
  
  a = 1.;
  before = clock();
  for(i=0;i<N;i++) a=sqrt(a+i);
  elapsed = (clock()-before)/CLOCKS_PER_SEC;
  printf("%f %f\n",elapsed,a);
  
  a = 1.;
  before = clock();
  for(i=0;i<N;i++) a=sin(3.*a);
  elapsed = (clock()-before)/CLOCKS_PER_SEC;
  printf("%f %f\n",elapsed,a);

  a = 1.;
  before = clock();
  for(i=0;i<N;i++) a=exp(1./a);
  elapsed = (clock()-before)/CLOCKS_PER_SEC;
  printf("%f %f\n",elapsed,a);

  return 0;
}



#include <stdio.h>
#include <time.h>

int main() {
  int i,j,k=0;
  double before,elapsed;

  before = clock();
  for(i=0;i<100000;i++) {
    for(j=1;j<10000;j++) {
      k=i/j+k;
      //k=i%j+k;
    }
  }
  elapsed = (clock()-before)/CLOCKS_PER_SEC;
  printf("%f %d\n",elapsed,k);
  return 0;
}



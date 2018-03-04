#include <stdio.h>
#include <math.h>

int main() {
  int i,j,k=0;
  for(i=0;i<100000;i++) {
    for(j=1;j<10000;j++) {
      k=i/j;
    }
  }
  printf("%d\n",k);
  return 0;
}



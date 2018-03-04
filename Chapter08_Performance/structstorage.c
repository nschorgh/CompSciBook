#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  //struct {short int a; float b;} s;
  struct {int a; double b;} s;
  
  printf("%ld %ld\n",sizeof(int) + sizeof(double),sizeof(s));
  return 0;
}

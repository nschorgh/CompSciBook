#include<stdio.h>

int main() {
  int year;
  float T;
  FILE *fin;
  fin = fopen("file.dat","r");
  while (  fscanf(fin,"%d %f\n",&year,&T) >0 )
    printf("%d %f\n",year,T);

  return(0);
}


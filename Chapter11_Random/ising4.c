#include<math.h>
#include<stdio.h>
#include<stdlib.h>

/* Magnetization versus temperature for 
   1-D, 2-D, and 3-D Ising model 

   like ising3.c, but uses different transition probabilities

   critical temperature in 2D: Tc=2.269*J/k
*/

float ran1(long *idum);

int main() {
  const int N1=4*1024/4,N2=1,N3=1;  // for 1D
  //const int N1=64,N2=64,N3=1;  // for 2D
  int i,j,m,k,s[N1+2][N2+2][N3+2],E,mag,count;
  float T,x,avm;
  long idum=-23940;  // for1D
  //long idum=-23941;  // for2D

  for(T=0.;T<=3.5;T+=0.1) {
    for(i=0;i<=N1+1;i++) for(j=0;j<=N2+1;j++) for(k=0;k<=N3+1;k++) 
      s[i][j][k]=1;  // for 2D
      //s[i][j][k]=(rand()%2)*2-1;  // for 1D
    s[0][1][1]=s[N1][1][1];  s[N1+1][1][1]=s[1][1][1];  // for 1D
    mag=0; count=0;
    for(m=0;m<5*4000*N1*N2*N3;m++) {
      i=rand()%N1+1; j=rand()%N2+1; k=rand()%N3+1;
      E=-s[i][j][k]*  
	(s[i+1][j][k]+s[i-1][j][k]);    // for 1D
      //(s[i+1][j][k]+s[i-1][j][k]+s[i][j+1][k]+s[i][j-1][k]);  // for 2D
      //(s[i+1][j][k]+s[i-1][j][k]+s[i][j+1][k]+s[i][j-1][k]+s[i][j][k-1]+s[i][j][k+1]);
      if (E>=0.) s[i][j][k]*=-1;
      else {
	x=ran1(&idum); 
	if (x<exp(2.*E/T)) s[i][j][k]*=-1;
      }
      if (i==1) s[N1+1][j][k]=s[i][j][k]; 
      if (i==N1) s[0][j][k]  =s[i][j][k];
      if (N2>1) {
	if (j==1) s[i][N2+1][k]=s[i][j][k];
	if (j==N2) s[i][0][k]  =s[i][j][k];
      }
      if (N3>1) {
	if (k==1) s[i][j][N3+1]=s[i][j][k]; 
	if (k==N3) s[i][j][0]  =s[i][j][k];
      }

      if (m>5*2000*N1*N2*N3 && m%(10*N1*N2*N3)==0) {
	for(i=1;i<=N1;i++) for(j=1;j<=N2;j++) for(k=1;k<=N3;k++) 
	  mag+=s[i][j][k];
	count++;
      }
    }
    avm=((float)mag)/((float)N1*N2*N3*count);
    printf("%g %g\n",T,avm);
    /* for (i=0;i<N1;i++) 
      if (s[i][1][1]==1) printf("+");
      else printf("-");
      printf("\n"); */
  }
  return(0);
}


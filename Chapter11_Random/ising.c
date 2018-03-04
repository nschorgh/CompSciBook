#include<math.h>
#include<stdio.h>
#include<stdlib.h>

/* used for figures in book */

// critical temperature Tc=2.269*J/k

float ran1(long *idum);

int main() {
  const int N=64;
  const float T=2.3;
  int i,j,m,s[N+2][N+2],E;
  float x;
  //long idum=-2394;   //a
  long idum=-2395;   //b
  for(i=1;i<=N;i++) for(j=1;j<=N;j++) s[i][j]=2*(rand()%2)-1;
  for(i=1;i<=N;i++) {
    s[0][i]=s[N][i]; s[N+1][i]=s[1][i];
    s[i][0]=s[i][N]; s[i][N+1]=s[i][1];
  }
  for(m=0;m<1000*N*N;m++) { // For T=2 and T=5 figures
  //for(m=0;m<10000*N*N;m++) {
    i=rand()%N+1; j=rand()%N+1;
    E=s[i][j]*(s[i+1][j]+s[i-1][j]+s[i][j+1]+s[i][j-1]);
    x=ran1(&idum); // random number between 0 and 1
    //printf("%d %d %g\n",i,j,exp(E/T));
    if (x<1./(exp(2.*E/T)+1.)) s[i][j]*=-1;
    if (i==1) s[N+1][j]=s[1][j]; 
    if (i==N) s[0][j]  =s[N][j];
    if (j==1) s[i][N+1]=s[i][1];
    if (j==N) s[i][0]  =s[i][N];
  }
  for(i=1;i<=N;i++) {
    for(j=1;j<=N;j++) { 
      printf("%d ",s[i][j]); 
    }
    printf("\n");
  }
  return(0);
}


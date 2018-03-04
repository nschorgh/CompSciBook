#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float ran1(long *idum);

void showstate(int s[], int N) {
  int i;
  for (i=0;i<N;i++) 
    if (s[i]==1) printf("+");
    else printf("-");
  printf("\n");
}

int main() {
  const int N=10;
  const float T=2.3*0;
  int i,j,s[N],E,jp1,jm1,sold;
  float x,m=0.;
  long idum=-2395; 

  for (i=0;i<N;i++) {
    s[i]=2*(rand()%2)-1;
    s[i]=1;
    m+=(float)s[i];
  }
  printf("%f\n",m/N);
  //showstate(s,N);

  for (i=0;i<1000*N;i++) {
    showstate(s,N);
    j=rand()%N;
    jp1=j+1; if(jp1>=N) jp1=0;
    jm1=j-1; if(jm1<0) jm1=N-1;
    E=-s[j]*(s[jm1]+s[jp1]);  // energy of unflipped spin
    sold=s[j];
    if (E>=0.) s[j]=-s[j]; // currently in high energy state or zero energy
    if (E<0.) { // currently in low energy state
      x=ran1(&idum); // random number between 0 and 1
      if (x<exp(E/T)) s[j]=-s[j]; 
    }
    //printf("%5.1f %d\n",(float)E,sold*s[j]);
  }    
  for (m=0.,i=0;i<N;i++) m+=(float)s[i];
  printf("%f\n",m/N); 
  //showstate(s,N);
  return 0;
}
  
/* T=2.3

-2.0   1  15375
-2.0  -1  10809  
 2.0   1  15375 -> 0
 0.0   1      0

10809/(10809+15375) = 0.41
exp(-2./T)=0.42 


test I went through:
see initial condition is right
see if T=0 gives me all alignment
calculate probabilties from output statistics: E, flip
check critical temperatures

*/


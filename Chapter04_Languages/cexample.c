/* C program */
#include <math.h>
#include <stdio.h>

void main()  {           
   int i;            
   const int N=64;   
   float b,a[N];
   b=-2.;
   for(i=0;i<N;i++) {
      a[i]=sin(i/2.);  
      if (a[i]>b) b=a[i];
   }
   b=pow(b,5.); b=b/N;
   printf("%f\n",b);
}

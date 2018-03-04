#include <stdio.h>
#include <math.h>

int main()
{  float y,y1,y2=1.;
   int n;
   y1=0.3333;
   //y1=1./3;
   printf("%d  %g  %g\n",0,1./pow(3.,0),y2);
   printf("%d  %g  %g\n",1,1./pow(3.,1),y1);
   for(n=2;n<=15;n++) {
      y=(7*y1-2*y2)/3.;
      y2=y1;
      y1=y;
      printf("%d  %g  %g\n",n,1./pow(3.,n),y);
   }
   return 0;
}

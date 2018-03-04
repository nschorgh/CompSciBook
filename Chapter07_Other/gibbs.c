#include<math.h>
#include<stdio.h>

int main() {
  int n;
  double x,y,y0;
  const double pi=3.141592653589793238;
  for(x=-pi;x<=pi;x+=0.001) {
    y=0.;
    y0=0.;
    for(n=1;n<=51;n+=2)
      y+=sin(n*(x+pi/2.))/(double)n;
    y=2./pi*y+0.5;
    if (x>-pi/2. && x<pi/2.) y0=1.;
    printf("%g %lg %f\n",x,y,y0);
  }
  return(0);
}

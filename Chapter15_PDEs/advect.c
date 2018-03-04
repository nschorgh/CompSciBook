#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "/home/norbert/Research/Nrc/nrutil.h"


// Gauss-Jordan matrix inversion and linear equation solution from Numerical Recipes
void gaussj(float **a, int n, float **b, int m);


void shifts(double f[], int N, int shift) {
  int j,k;
  double g[N+2];
  for(j=1;j<=N;j++) {
    k=j+shift;
    if (k>N) k-=N;
    if (k<1) k+=N;
    g[j]=f[k];
  }
  for(j=1;j<=N;j++) f[j]=g[j];
  f[N+1]=g[1]; f[0]=g[N];
}


void prebuild(double v, double k, double h, int N, float **a) {
  /* solves tridiagonal system with periodic boundary condition, y=A*x */
  int j,jp1,jm1,i;
  float **b;
  b=matrix(1,N,1,1);
  for (j=1;j<=N;j++) {
    a[j][j]=1.;
    jp1=j+1; if (jp1>N) jp1-=N;
    a[j][jp1]=v*k/(2*h);
    jm1=j-1; if (jm1<1) jm1+=N;
    a[j][jm1]=-v*k/(2*h);
    //b[j][1]=0.;
  }
  /* for(j=1;j<=N;j++) {
    for(i=1;i<=N;i++) printf("%f ",a[i][j]);
    printf("\n");
    } */
  gaussj(a,N,b,1);
  /*for(j=1;j<=N;j++) {
    for(i=1;i<=N;i++) printf("%f ",a[i][j]);
    printf("\n");
    } */ 
}


int main() {
  const int N=64;
  int i,j,shift,l;
  double f[N+2],fn[N+2],ini[N+2],fold[N+2];
  const double pi=3.14159265358979;
  const double h=1./N, k=0.9*h,v=1.;
  float **a;
  a=matrix(1,N,1,N);
  prebuild(v,k,h,N,a);
  for(j=1;j<=N;j++) {
    //f[j]=sin(j*h*2.*pi);
    //if (j<N/2) f[j]=1.; if (j>N/2) f[j]=0.;
    //if (j==N/2) f[j]=0.5;
    //f[j]=cos(j*2*pi/N)*sin(j*6*pi/N+0.3);
    f[j]=cos(j*2*pi/N)*sin(j*6*pi/N+0.3)+0.02*sin(j*17.*pi/N);
  }
  f[N+1]=f[1]; f[0]=f[N];
  for(j=0;j<=N+1;j++) ini[j]=f[j];
  for(j=1;j<=N;j++) fold[j]=f[j]+v*k/h*(f[j+1]-f[j-1]); //2
  for(i=0;i<10;i++) {
    for(j=1;j<=N;j++) {
      //fn[j]=f[j]-v*k/h*(f[j+1]-f[j-1]); //1
      //fn[j]=0.; for(l=1;l<=N;l++) fn[j]+=a[j][l]*f[l];  //2
      //fn[j]=fold[j]-v*k/h*(f[j+1]-f[j-1]); //3
      fn[j]=(1-v*k/h)/2*f[j+1]+(1+v*k/h)/2*f[j-1]; //4
    }
    for(j=0;j<=N+1;j++) fold[j]=f[j];
    for(j=1;j<=N;j++) f[j]=fn[j];
    f[N+1]=fn[1]; f[0]=fn[N];
  }
  shift=-9;
  shifts(ini,N,shift);
  for(j=1;j<=N;j++)
    printf("%g %g %g\n",j*h,f[j],ini[j]);
  return 0;
}

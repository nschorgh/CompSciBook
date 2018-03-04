% Matlab program that measure time for matrix solver

N=4000;

A=rand(N,N);
b=rand(N,1);

x=A\b;
norm(A*x-b)

tic; x=A\b; toc


% Matlab program that measures time for matrix solver

N=4000;

A=rand(N,N);
b=rand(N,1);

% always test
x=A\b;
norm(A*x-b)

tic; x=A\b; toc


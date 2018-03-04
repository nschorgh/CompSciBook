; IDL program example

N=64
a=FLTARR(N)
FOR i=0,N-1 DO a(i)=sin(i/2)
b=MAX(a)
PRINT, b^5/N


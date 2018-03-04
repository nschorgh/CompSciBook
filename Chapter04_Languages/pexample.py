# Python program example
N=64
from math import sin
a=[]
for i in range (0,N-1):
  a.append(sin(i/2.))
b=max(a)
print b**5/N

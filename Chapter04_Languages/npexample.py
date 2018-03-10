# NumPy program example
import numpy
N=64
a=numpy.zeros(N)
for i in range (0,N):
    a[i]=numpy.sin(i/2.)
b=max(a)
print b**5/N

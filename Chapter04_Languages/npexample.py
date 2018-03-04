# NumPy program example
import numpy as np
N=64
a=np.zeros(N)
for i in range (0,N):
    a[i]=np.sin(i/2.)
b=max(a)
print b**5/N

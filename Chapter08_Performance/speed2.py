import math
import numpy

a = 1.
for i in np.arange(1,1000000000/100):
    a=a+12.1
    #a=a*1.0000001
    #a=a/1.0000001
    #a=math.sin(3.*a)

print a

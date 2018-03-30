# Python3 version of speed.py
import math 

a = 1.
for i in range(1,100000000):
    a=a+12.1
    #a=a*1.0000001
    #a=a/1.0000001
    #a=math.sin(3.*a)

print(a)

# R program

N=64   
b=-2.
a <- array(1:N)
for (i in 1:N) {
   a[i] <- sin(i/2.)
   if (a[i]>b) b <- a[i]
}
b=b**5; b=b/N
print(b);


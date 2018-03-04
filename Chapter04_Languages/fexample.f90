! Fortran program example

program demo 
   implicit none
   integer i
   integer,parameter :: N=64
   real b,a(N)
   b=-2.
   do i=1,N
      a(i)=sin((i-1)/2.)
      if (a(i)>b) b=a(i)
   enddo
   b=b**5; b=b/N
   print *,b
end 

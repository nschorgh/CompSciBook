      PROGRAM newton_example
C     solve sin(3x)=x with Newton method
C	  or use to take square roots
      implicit none
      real(8) x
      integer j
      x=1. 
C      x=2.
      do j=0,9
         write(*,*) j,x
         x=x-(sin(3*x)-x)/(3*cos(3*x)-1.)
C         x=x-(x**2-2.)/(2.*x) 
      enddo
      print *,'f(x)=',sin(3*x)-x
C      print *,'x-sqrt(2)=',sqrt(2.)-x
      END


      PROGRAM xrtbis
      implicit none
      REAL X1,X2, example
      EXTERNAL example
      integer j
      real f1,f2,xmid,fmid
      x1=0.1;  x2=2.0
      write(*,'(/1a,1x,t9,a,t9,a/)') '#','x','F(x)'

      f1=example(x1)
      f2=example(x2)
      do j=1,18
         xmid= (x1+x2)/2.
         fmid = example(xmid)
         if (fmid*f1>0.) then
            x1=xmid
            f1=fmid
         else
            x2=xmid
            f2=fmid
         endif
         write(*,'(i2,1x,f7.4,1x,f7.4)') j,x1,x2
      enddo
      END


      function example(x)
      implicit none
      real x, example
      example= sin(3.*x)-x
      return
      end

C     closely based on 1986-92 Numerical Recipes (C) 

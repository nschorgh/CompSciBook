      program pipi
      implicit none

      real pi1,almost1
      double precision pi2,almost2
      parameter (pi1=3.1415927)
      parameter (pi2=3.141592653589793d0)

      write(6,'(f20.8)') pi1
      write(6,'(f20.17)') pi2

      print *
      almost1=pi1-2.**(-24)
      print *,pi1,almost1
      almost2=pi2+2.**(-52)
      write(6,'(f20.17)') pi2,almost2

      print *
      print *,tan(pi1/2.)
      print *,tan(pi2/2.)
      end

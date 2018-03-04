program speedtest
  implicit none
  integer i
  real(8) :: a=1.
  
  do i=1,1000000000
     a=a+12.1
     !a=a*1.0000001d0
     !a=a/1.0000001d0
     !a=sin(3.*a)
  end do
  print *,a  ! make sure it didn't overflow
end program speedtest



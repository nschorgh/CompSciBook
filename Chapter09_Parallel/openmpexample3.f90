program openmpexample
  ! not openMP, but analogous to openmpexample
  implicit none
  integer i,k
  real(8) :: x 

  do concurrent (i=1:10) ! but no multi-core for this yet
     x=i
     do k=1,100000000
        x=sin(3*x)
     enddo
     print *,'Hello world',i
  end do
end program openmpexample


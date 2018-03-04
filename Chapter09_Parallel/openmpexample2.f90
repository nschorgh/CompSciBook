program openmpexample
  ! gfortran -fopenmp openmpexample.f90
  use omp_lib
  implicit none
  integer i,k
  real(8) :: x 

  !$OMP PARALLEL DO 
  do i=1,10
     x=i
     do k=1,100000000
        x=sin(3*x)
     enddo
     print *,'Finished',i
  end do
  !$OMP END PARALLEL DO
end program openmpexample


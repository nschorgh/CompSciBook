program openmpexample
  ! gfortran -fopenmp -Wall openmpexample.f90
  use omp_lib
  implicit none

  !$OMP PARALLEL 
  print *,'Hello world'
  !$OMP END PARALLEL

end program openmpexample


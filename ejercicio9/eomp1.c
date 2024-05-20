#include "stdio.h"
#include "omp.h"
int main()
{
  int cantidad, procesadoractivo;
  int i=0;
  #pragma omp parallel
  {
    
    cantidad = omp_get_num_threads();
    procesadoractivo=omp_get_thread_num();
    printf("Procesadores %d-activo %d-%d\n",cantidad,procesadoractivo, i);
    i=i+1;
  }
  printf("valor i %d\n", i);
  return 0;
}




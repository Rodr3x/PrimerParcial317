#include "stdio.h"
#include "mpi.h"

#define N 1000000 // Número total de subintervalos

double f(double x) {
    return 4.0 / (1.0 + x * x); // SUMA DE RIEMMAN
}

int main() {
    int num_procesos, rango_proceso;
    double suma = 0.0, suma_local = 0.0;
    double paso = 1.0 / N; // Tamaño del subintervalo

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procesos);
    MPI_Comm_rank(MPI_COMM_WORLD, &rango_proceso);
    
    int subintervalos_por_proceso = (N + num_procesos - 1) / num_procesos;
    int indice_inicio = rango_proceso * subintervalos_por_proceso;
    int indice_fin = (rango_proceso + 1) * subintervalos_por_proceso;

    for (int i = indice_inicio; i < indice_fin && i < N; i++) {
        double x = (i + 0.5) * paso;
        suma_local += f(x);
    }

    MPI_Reduce(&suma_local, &suma, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rango_proceso == 0) {
        double pi = suma * paso;
        printf("Aproximación de Pi: %f\n", pi);
    }

    MPI_Finalize();
    return 0;
}






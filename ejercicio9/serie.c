#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int n = 20; // Número de términos
    int rank, size;
    int v[n];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int ns = n / size;
    int r = n % size;
    int ini, fin;

    if (rank < r) {
        ini = rank * (ns + 1);
        fin = ini + ns + 1;
    } else {
        ini = rank * ns + r;
        fin = ini + ns;
    }

    printf("Proceso %d maneja los índices %d a %d\n", rank, ini, fin - 1);

    for (int j = ini; j < fin; j++) {
        v[j] = 2 * j + 2;
        printf("Proceso %d genera v[%d] = %d\n", rank, j, v[j]);
    }

    int v_final[n];
    MPI_Gather(&v[ini], fin - ini, MPI_INT, v_final, fin - ini, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Vector final: ");
        for (int i = 0; i < n; i++)
            printf("%d, ", v_final[i]);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}


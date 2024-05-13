#include <stdio.h>
#include <mpi.h>

#define N 3

#define MATRIZ {{2, 2, 3}, \
                {1, 2, 3}, \
                {3, 2, 3}}

#define VECTOR {1, 2, 3}

#define RESULTADO {0, 0, 0}

int main(int argc, char *argv[]) {
    int rank, size;
    int mtr[N][N] = MATRIZ;
    int v[N] = VECTOR;
    int r[N] = RESULTADO;
    int fila, columna;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int num_procs = size;

    for (fila = rank; fila < N; fila += num_procs) {
        r[fila] = 0;
        for (columna = 0; columna < N; columna++) {
            r[fila] += mtr[fila][columna] * v[columna];
        }
    }

    MPI_Allgather(r + rank, 1, MPI_INT, r, 1, MPI_INT, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Resultado de la multiplicación:\n");
        for (fila = 0; fila < N; fila++) {
            printf("%d ", r[fila]);
        }
        printf("\n");
    }

    MPI_Finalize();

    return 0;
}

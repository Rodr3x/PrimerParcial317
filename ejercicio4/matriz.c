#include <stdio.h>
#include <omp.h>

#define N 3

#define MATRIZ {{2, 2, 3}, \
                {1, 2, 3}, \
                {3, 2, 3}}

#define VECTOR {1, 2, 3}

#define RESULTADO {0, 0, 0}

int main() {
    int mtr[N][N] = MATRIZ;
    int v[N] = VECTOR;
    int r[N] = RESULTADO;
    int fila, columna;

    // Multiplicación de matriz por vector con OpenMP
    #pragma omp parallel for private(fila, columna) shared(mtr, v, r)
    for (fila = 0; fila < N; fila++) {
        for (columna = 0; columna < N; columna++) {
            r[fila] += mtr[fila][columna] * v[columna];
        }
    }

    printf("Resultado:{ ");
    for (fila = 0; fila < N; fila++) {
        printf("%d ", r[fila]);
    }
    printf("}\n");

    return 0;
}

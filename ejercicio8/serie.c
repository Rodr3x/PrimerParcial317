#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10; // Número de términos
    int m = 2;  // Número de procesadores
    int v[n];
    int sec = n / m;
    int r = n % m;

    omp_set_num_threads(m);

    #pragma omp parallel
    {
        int proc = omp_get_thread_num();
        int ini, fin;
        if (proc < r) {
            ini = proc * (sec + 1);
            fin = ini + sec + 1;
        } else {
            ini = proc * sec + r;
            fin = ini + sec;
        }

        printf("Procesador %d maneja los índices %d a %d\n", proc, ini, fin - 1);
        for (int x = ini; x < fin; x++) {
            v[x] = 2 * x + 2;
            printf("Procesador %d genera v[%d] = %d\n", proc, x, v[x]);
        }
    }

    printf("Vector final: ");
    for (int i = 0; i < n; i++)
        printf("%d, ", v[i]);
    printf("\n");

    return 0;
}




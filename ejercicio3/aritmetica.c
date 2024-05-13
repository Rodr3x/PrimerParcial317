#include <stdio.h>
#include <omp.h>

int mult(int x, int y) {
    int r = 0;
    int i; 
    #pragma omp parallel for reduction(+:r) private(i)
    for (i = 0; i < y; i++) {
        int id_pa = omp_get_thread_num();
        printf("Procesador activo en hilo %d - Cálculo: %d * %d = %d\n",
                                id_pa, x, i, x * i);
        r += x;
    }
    return r;
}

int div(int x, int y) {
    if (y == 0) {
        printf("Error: División por cero\n");
        return 0;
    }
    int r = 0;
    int temp = x;
    int id_pa; 
    #pragma omp parallel private(id_pa)
    {
        id_pa = omp_get_thread_num();
        #pragma omp single
        while (temp >= y) {
            temp -= y;
            r++;
            printf("Procesador activo en hilo %d - Cálculo: %d - %d = %d\n",
                            id_pa, temp + y, y, temp);
        }
    }
    return r;
}

int main() {
    int numero1, numero2;

    printf("Introduce el primer número: ");
    scanf("%d", &numero1);
    printf("Introduce el segundo número: ");
    scanf("%d", &numero2);

    printf("Multiplicación: %d\n", mult(numero1, numero2));

    printf("División: %d\n", div(numero1, numero2));

    return 0;
}

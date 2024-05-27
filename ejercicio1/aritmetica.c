#include <stdio.h>

int suma(int *a, int *b) {
    return *a + *b;
}

int resta(int *a, int *b) {
    return *a - *b;
}

int multiplicacion(int *a, int *b) {
    int r = 0;
    int uno = 1;
    for (int i = 0; i < *b; i = suma(&i, &uno)) {
        r = suma(&r, a);
    }
    return r;
}

float division(int *a, int *b) {
    if (*b == 0) {
        printf("Error: División por cero\n");
        return 0;
    }
    int r = 0;
    int temp = *a;
    int uno = 1;
    while (temp >= *b) {
        temp = resta(&temp, b);
        r = suma(&r, &uno);
    }
    return (float)r;
}

int main() {
    int numero1, numero2;

    // input de n1 y n2
    printf("Ingrese el primer número: ");
    scanf("%d", &numero1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &numero2);

    printf("Suma: %d\n", suma(&numero1, &numero2));
    printf("Resta: %d\n", resta(&numero1, &numero2));
    printf("Multiplicación: %d\n", multiplicacion(&numero1, &numero2));
    printf("División: %.2f\n", division(&numero1, &numero2));

    return 0;
}

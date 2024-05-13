#include <iostream>

int suma(int *a, int *b) {
    return *a + *b;
}

int resta(int *a, int *b) {
    return *a - *b;
}

int multiplicacion(int *a, int *b) {
    int resultado = 0;
    for (int i = 0; i < *b; i++) {
        resultado += *a;
    }
    return resultado;
}

float division(int *a, int *b) {
    if (*b == 0) {
        std::cout << "Error: División por cero" << std::endl;
        return 0;
    }
    float resultado = 0;
    float temp = *a;
    while (temp >= *b) {
        temp -= *b;
        resultado++;
    }
    return resultado;
}

int main() {
    int numero1, numero2;

    // input n1 y n2
    std::cout << "Ingrese el primer número: ";
    std::cin >> numero1;
    std::cout << "Ingrese el segundo número: ";
    std::cin >> numero2;

    std::cout << "Suma: " << suma(&numero1, &numero2) << std::endl;
    std::cout << "Resta: " << resta(&numero1, &numero2) << std::endl;
    std::cout << "Multiplicación: " << multiplicacion(&numero1, &numero2) << std::endl;
    std::cout << "División: " << division(&numero1, &numero2) << std::endl;

    return 0;
}

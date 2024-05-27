#include <iostream>

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
        std::cout << "Error: División por cero" << std::endl;
        return 0;
    }
    int r = 0;
    int temp = *a;
    int uno = 1;
    while (temp >= *b) {
        temp = resta(&temp, b);
        r = suma(&r, &uno);
    }
    return static_cast<float>(r);
}

int main() {
    int numero1, numero2;

    // input de n1 y n2
    std::cout << "Ingrese el primer número: ";
    std::cin >> n1;
    std::cout << "Ingrese el segundo número: ";
    std::cin >> n2;

    std::cout << "Suma: " << suma(&n1, &n2) << std::endl;
    std::cout << "Resta: " << resta(&n1, &n2) << std::endl;
    std::cout << "Multiplicación: " << multiplicacion(&n1, &2) << std::endl;
    std::cout << "División: " << division(&n1, &n2) << std::endl;

    return 0;
}

// main.c
#include <stdio.h>

// Declaración (extern) de la variable definida en otro archivo
extern double PI;

// Declaración de funciones externas
double calcular_circunferencia(double radio);
double calcular_area(double radio);

int main() {
    double radio = 5.0;

    printf("Radio: %.2f\n", radio);
    printf("Circunferencia: %.15f\n", calcular_circunferencia(radio));
    printf("Área: %.15f\n", calcular_area(radio));

    return 0;
}


/*
math_utils.c
#include <stdio.h>

// Definición de la variable global externa
double PI = 3.141592653589793;

// Función para calcular la circunferencia de un círculo
double calcular_circunferencia(double radio) {
    return 2 * PI * radio;
}

// Función para calcular el área de un círculo
double calcular_area(double radio) {
    return PI * radio * radio;
}
*/
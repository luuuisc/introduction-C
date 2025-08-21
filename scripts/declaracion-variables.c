#include <stdio.h>

int main() {
    // Declaración de variables
    int edad;             // Entero
    float altura;         // Número decimal
    char inicial;         // Carácter
    double peso;          // Número decimal más preciso

    // Inicialización
    edad = 20;
    altura = 1.75;
    inicial = 'J';
    peso = 70.5;

    // Uso de variables (impresión en pantalla)
    printf("Edad: %d años\n", edad);
    printf("Altura: %.2f metros\n", altura);
    printf("Inicial del nombre: %c\n", inicial);
    printf("Peso: %.1f kg\n", peso);

    // Ejemplo de operación con variables
    int edadProxima = edad + 1;
    printf("El próximo año tendrás %d años\n", edadProxima);

    return 0;
}

# 📦 Declaración y uso de variables en C

En C, **una variable** es un espacio de memoria con un nombre, destinado a almacenar datos que pueden cambiar durante la ejecución del programa.

---

## 🛠 Declaración de variables

Para declarar una variable se especifica:

```
<tipo_de_dato> <nombre_variable>;
```

### Ejemplos:
```c
int edad;
float precio;
char letra;
```

También puedes **inicializarla** (darle un valor desde el inicio):

```c
int edad = 25;
float precio = 19.99;
char letra = 'A';
```

Se pueden **declarar** variables separadas por coma 

```c
int a, b, c;
float x, y;
```

---

## Reglas para nombres de variables

* Deben comenzar con una letra o guion bajo (`_`).
* Pueden contener letras, números y guiones bajos.
* No pueden contener espacios ni caracteres especiales.
* No pueden ser **palabras reservadas** del lenguaje (`int`, `return`, `if`, etc.).
* Se recomienda usar nombres descriptivos (`contador`, `promedio`, `temperaturaCelsius`).

---

## 🔢 Tipos de almacenamiento

En C, las variables también tienen **clases de almacenamiento** que afectan su **tiempo de vida** y **alcance**:

| Palabra clave        | Alcance                 | Tiempo de vida          | Ejemplo de uso                                   |
| -------------------- | ----------------------- | ----------------------- | ------------------------------------------------ |
| `auto` (por defecto) | Bloque actual           | Mientras dure el bloque | Variables locales en funciones                   |
| `static`             | Bloque o archivo        | Toda la ejecución       | Contadores persistentes                          |
| `extern`             | Global (definida fuera) | Toda la ejecución       | Compartir variables entre archivos               |
| `register`           | Bloque actual           | Mientras dure el bloque | Sugerencia al compilador para usar registros CPU |

---

## 🧩 Ejemplo de variables locales y globales

```c
#include <stdio.h>

int contadorGlobal = 0; // variable global

void incrementar() {
    static int contadorLocal = 0; // persiste entre llamadas
    contadorLocal++;
    contadorGlobal++;
    printf("Local: %d - Global: %d\n", contadorLocal, contadorGlobal);
}

int main() {
    incrementar();
    incrementar();
    incrementar();
    return 0;
}
```

**Salida:**

```
Local: 1 - Global: 1
Local: 2 - Global: 2
Local: 3 - Global: 3
```

---

## 🎯 Buenas prácticas

* Inicializar siempre las variables antes de usarlas.
* Usar nombres descriptivos y consistentes.
* Reducir el uso de variables globales para evitar errores difíciles de rastrear.
* Declarar variables lo más cerca posible de donde se usan.

---

## Ejemplo práctico completo

```c
#include <stdio.h>

int main() {
    int edad = 20;         // entero
    float altura = 1.75;   // punto flotante
    char inicial = 'J';    // carácter

    printf("Edad: %d\n", edad);
    printf("Altura: %.2f\n", altura);
    printf("Inicial: %c\n", inicial);

    return 0;
}
```
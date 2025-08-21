# 🌍 Manejo de variables externas y precisión numérica en C

En este apunte veremos dos temas clave en C:

1. **Variables externas (`extern`)**
2. **Precisión numérica en cálculos**

---

## 🔹 Variables externas en C

En C, las variables **globales** pueden ser accedidas desde distintos archivos si se declara su existencia con la palabra clave `extern`.

### Declaración y uso

- **Definición**: Se crea en un archivo `.c`.
- **Declaración con `extern`**: Se avisa a otros archivos que la variable existe.

**Ejemplo con dos archivos:**

📂 `main.c`
```c
#include <stdio.h>

// Declaración (aviso de que existe en otro lugar)
extern int contador;

void incrementar();

int main() {
    incrementar();
    incrementar();
    printf("Valor final del contador: %d\n", contador);
    return 0;
}
````

📂 `contador.c`

```c
#include <stdio.h>

int contador = 0; // Definición de la variable

void incrementar() {
    contador++;
    printf("Contador: %d\n", contador);
}
```

**Notas:**

* Solo debe haber **una definición real** de la variable (en un archivo `.c`).
* `extern` evita múltiples definiciones.
* Es útil en proyectos grandes donde varias funciones necesitan compartir información.

---

## 🔹 Precisión numérica en C

Los cálculos numéricos pueden sufrir **errores de precisión** debido a la representación en punto flotante.

### 📊 Tipos numéricos de punto flotante

| Tipo          | Tamaño (bytes) | Precisión aprox.    | Rango típico               |
| ------------- | -------------- | ------------------- | -------------------------- |
| `float`       | 4              | 6-7 dígitos         | \~10^-38 a 10^38           |
| `double`      | 8              | 15-16 dígitos       | \~10^-308 a 10^308         |
| `long double` | 16 (depende)   | 18-19 dígitos o más | Implementación-dependiente |

---

### Ejemplo de pérdida de precisión

```c
#include <stdio.h>

int main() {
    float a = 0.1f + 0.2f;
    double b = 0.1 + 0.2;

    printf("Float: %.20f\n", a);
    printf("Double: %.20lf\n", b);

    return 0;
}
```

**Posible salida:**

```
Float: 0.30000001192092895508
Double: 0.29999999999999998890
```

➡️ El resultado esperado (`0.3`) no se representa exactamente, por las limitaciones del sistema binario.

---

### 🛠 Recomendaciones de buenas prácticas

* Usar **`double`** en lugar de `float` cuando la precisión sea importante.
* Para cálculos financieros o científicos críticos, usar **bibliotecas de precisión arbitraria** (ej. `gmp`, `mpfr`).
* Al comparar números de punto flotante, usar una **tolerancia** en lugar de igualdad exacta:

```c
#include <math.h>
#include <stdbool.h>

bool son_iguales(double x, double y) {
    return fabs(x - y) < 1e-9; // margen de error
}
```

---

## 🎯 Resumen

* **Variables externas (`extern`)**: permiten compartir variables entre distintos archivos, pero deben usarse con cuidado para evitar errores de diseño.
* **Precisión numérica**: depende del tipo de dato (`float`, `double`, `long double`), y siempre hay que considerar los errores de redondeo.


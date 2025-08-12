# 📚 Curso de Introducción a C

Este repositorio contiene los ejercicios y proyectos realizados durante mi curso de introducción al lenguaje **C**, ejecutado en macOS usando **VSCode** como editor.

---

## 🚀 Contenido

- `helloWorld.c` → Primer programa en C.
- Más ejercicios se irán agregando conforme avance el curso.

---

## 🧠 Tipos de datos en C

En C, los tipos de datos pueden ser **con signo** (`signed`) o **sin signo** (`unsigned`).  
Los valores **unsigned** no pueden ser negativos, lo que permite duplicar el rango positivo.

---

### Valores enteros

Pueden ser **con signo** (`signed`) o **sin signo** (`unsigned`), excepto `bool`.

| Tipo                  | Tamaño aprox. (bytes) | Signed / Unsigned | Rango aproximado |
|-----------------------|-----------------------|-------------------|------------------|
| `char`                | 1                     | ✅ / ✅            | `signed`: -128 a 127<br>`unsigned`: 0 a 255 |
| `short` / `short int` | 2                     | ✅ / ✅            | `signed`: -32,768 a 32,767<br>`unsigned`: 0 a 65,535 |
| `int`                 | 4                     | ✅ / ✅            | `signed`: -2,147,483,648 a 2,147,483,647<br>`unsigned`: 0 a 4,294,967,295 |
| `long`                | 8 (macOS 64-bit)      | ✅ / ✅            | `signed`: -9,223,372,036,854,775,808 a 9,223,372,036,854,775,807<br>`unsigned`: 0 a 18,446,744,073,709,551,615 |
| `long long`           | 8                     | ✅ / ✅            | Igual que `long` en 64 bits |
| `_Bool` / `bool`      | 1                     | ❌ / ❌            | `0` (false) o `1` (true) |

---

### Valores de punto flotante

No admiten `unsigned`. Se usan para representar números reales con decimales.

| Tipo           | Tamaño aprox. (bytes) | Precisión y ejemplo |
|----------------|-----------------------|---------------------|
| `float`        | 4                     | ~6-7 dígitos de precisión (ej: `3.141593`) |
| `double`       | 8                     | ~15-16 dígitos de precisión |
| `long double`  | 16 (depende compilador) | Mayor precisión (80-128 bits internos) |

---
### Tipo `void` en C

En C, `void` es un tipo especial que indica **ausencia de valor o de tipo**.  

No almacena datos y se utiliza principalmente en tres contextos:

---

### Funciones que **no devuelven valor**
Cuando una función se declara con `void` como tipo de retorno, significa que **no devuelve nada** al final de su ejecución.

```c
#include <stdio.h>

void saludar() {
    printf("Hola, mundo!\n");
}

int main() {
    saludar(); // No esperamos valor de retorno
    return 0;
}
```

> **Uso común:** Procedimientos que solo ejecutan acciones (mostrar datos, modificar variables globales, etc.).

---

### Funciones que **no reciben parámetros**

Cuando `void` aparece en la lista de parámetros de una función, indica que **no recibe argumentos**.

```c
void mostrarMensaje(void) {
    printf("Este mensaje no necesita parámetros.\n");
}
```

> Esto es diferente de dejar la lista de parámetros vacía, ya que en C antiguo (K\&R) una lista vacía implicaba que podían pasarse parámetros.

---

### Punteros genéricos: `void *`

Un puntero de tipo `void *` es un **puntero genérico** que puede apuntar a cualquier tipo de dato.
No se puede desreferenciar directamente sin hacer una conversión (`cast`) al tipo correcto.

```c
#include <stdio.h>

int main() {
    int numero = 42;
    void *ptr = &numero; // Apunta a un entero, pero es genérico

    // Necesitamos convertir antes de usarlo
    printf("Valor: %d\n", *(int *)ptr);
    return 0;
}
```
> **Uso común:** En funciones que deben recibir o manejar datos de distintos tipos, como `malloc()` en la biblioteca estándar.

---

### 📌 Resumen rápido:

* **`void` como retorno:** La función no devuelve valor.
* **`void` como parámetro:** La función no recibe argumentos.
* **`void *` como puntero:** Puede apuntar a cualquier tipo de dato, pero necesita conversión para usarse.

## 🛠 Configuración en macOS

1. **Instalar GCC (si no lo tienes)**  
   ```bash
   xcode-select --install
   ```

2. Compilar un programa
    
    ```bash
    gcc helloWorld.c -o helloWorld
    ```

3. Ejecutar

    ```bash
    ./helloWorld
    ```

---

## 📌 Notas

- Practicar siempre la compilación desde la terminal.
- Probar variaciones en los tipos de datos.
- Usar comentarios en el código (`// Comentario` o `/* Comentario */`).
- Por defecto, los enteros (`int`, `short`, `long`) son **signed** si no se especifica.
- El tamaño y rango exacto dependen del compilador y la arquitectura del procesador.
- Para verificar en tu sistema macOS ARM64, puedes usar:

    ```c
    #include <stdio.h>

    int main() {
        printf("Tamaño de char: %zu bytes\n", sizeof(char));
        printf("Tamaño de short: %zu bytes\n", sizeof(short));
        printf("Tamaño de int: %zu bytes\n", sizeof(int));
        printf("Tamaño de long: %zu bytes\n", sizeof(long));
        printf("Tamaño de long long: %zu bytes\n", sizeof(long long));
        printf("Tamaño de float: %zu bytes\n", sizeof(float));
        printf("Tamaño de double: %zu bytes\n", sizeof(double));
        printf("Tamaño de long double: %zu bytes\n", sizeof(long double));
        return 0;
    }
    ```

---

## 📄 Licencia

Este proyecto está bajo la licencia MIT.

---

## ✍🏼 Créditos 

- Curso de Introducción a C by [Platzi](https://platzi.com/)

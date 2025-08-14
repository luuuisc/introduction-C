# 🧱 Enums en C: constantes con nombre

Un `enum` (enumeración) te permite **definir constantes enteras con nombre** agrupadas por tema (estados, categorías, opciones de menú, etc.). Mejora la legibilidad y evita usar “números mágicos”.

> [!IMPORTANT]
> En C, los enumeradores son **constantes de tipo entero** (no strings). El **primer** valor es `0` por defecto y los siguientes **incrementan de 1**, salvo que asignes valores explícitos.

---

### ✅ ¿Por qué usar `enum`?
- **Legibilidad:** `ESTADO_ACTIVO` comunica mejor que `1`.
- **Agrupación lógica:** todas las constantes de un dominio quedan juntas.
- **Seguridad ligera:** el compilador puede advertir en `switch` si olvidas casos.
- **Mantenimiento:** cambiar un valor se hace en un solo lugar.

---

### 🧩 Sintaxis básica

```c
// Declaración tradicional
enum Dia { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };

// Uso
enum Dia hoy = LUNES;

// Con typedef (más cómodo)
typedef enum {
    ROJO = 1, VERDE, AZUL  // VERDE=2, AZUL=3
} Color;

Color c = AZUL;
```

**Reglas útiles**

* Puedes **asignar valores**:

  ```c
  enum Codigo { OK = 0, WARN = 10, ERROR = 100, FATAL = 100 }; // valores repetidos permitidos
  ```
* El **tipo subyacente** es un entero (implementación-definido). No asumir un tamaño fijo.
* Convención recomendada: **`TipoPascalCase`** para el enum y **`CONSTANTE_SNAKE_CASE`** para sus miembros.

---

## 🛠️ Ejemplos prácticos

### 1) Constantes para niveles de log

```c
#include <stdio.h>

typedef enum {
    LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR
} LogLevel;

void log_msg(LogLevel lvl, const char *msg) {
    switch (lvl) {
        case LOG_DEBUG: printf("[DEBUG] %s\n", msg); break;
        case LOG_INFO:  printf("[INFO ] %s\n", msg); break;
        case LOG_WARN:  printf("[WARN ] %s\n", msg); break;
        case LOG_ERROR: printf("[ERROR] %s\n", msg); break;
        // sin default → el compilador puede advertir si agregas niveles y olvidas manejarlos
    }
}

int main(void) {
    log_msg(LOG_INFO, "Aplicación iniciada");
    return 0;
}
```

---

### 2) Índices seguros para arreglos (mapeo a texto)

```c
#include <stdio.h>

typedef enum { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO, DIA_COUNT } Dia;

static const char *DIA_NOMBRE[DIA_COUNT] = {
    "Lunes","Martes","Miércoles","Jueves","Viernes","Sábado","Domingo"
};

int main(void) {
    Dia hoy = VIERNES;
    printf("Hoy es %s\n", DIA_NOMBRE[hoy]);
    return 0;
}
```

---

### 3) Opciones de menú con `switch`

```c
#include <stdio.h>

typedef enum {
    MENU_SALUDAR = 1,  // empezamos en 1 para usuarios
    MENU_SUMAR,
    MENU_SALIR
} Menu;

int main(void) {
    int op = 0;
    do {
        printf("1) Saludar\n2) Sumar\n3) Salir\n> ");
        if (scanf("%d", &op) != 1) return 1;

        switch ((Menu)op) {
            case MENU_SALUDAR: puts("¡Hola!"); break;
            case MENU_SUMAR:   puts("2 + 2 = 4"); break;
            case MENU_SALIR:   puts("Adiós!"); break;
            default:           puts("Opción inválida"); break;
        }
    } while (op != MENU_SALIR);
    return 0;
}
```

---

### 4) **Flags** (bitmasks) con `enum` para permisos

> Útiles cuando quieres **combinar** opciones con OR (`|`) y probar con AND (`&`).

```c
#include <stdio.h>

typedef enum {
    PERM_LEER  = 1 << 0, // 001
    PERM_ESCR  = 1 << 1, // 010
    PERM_EJEC  = 1 << 2  // 100
} Perm;

int main(void) {
    unsigned permisos = PERM_LEER | PERM_ESCR; // combinar

    if (permisos & PERM_LEER) puts("Tiene lectura");
    if (permisos & PERM_EJEC) puts("Tiene ejecución");
    else                      puts("No tiene ejecución");

    // Quitar un permiso
    permisos &= ~PERM_ESCR;

    return 0;
}
```

> 📝 Aunque el enum define nombres, la **variable que guarda flags** conviene que sea `unsigned` (o `unsigned int`) para operaciones bit a bit.

---

### 5) Máquina de estados simple

```c
#include <stdio.h>

typedef enum { ST_INICIO, ST_LEYENDO, ST_ERROR, ST_FIN } Estado;

int main(void) {
    Estado st = ST_INICIO;

    // Transiciones de ejemplo
    st = ST_LEYENDO;
    // ... si ocurre un problema:
    // st = ST_ERROR;

    switch (st) {
        case ST_INICIO:  puts("Inicio"); break;
        case ST_LEYENDO: puts("Leyendo"); break;
        case ST_ERROR:   puts("Error"); break;
        case ST_FIN:     puts("Fin"); break;
    }
    return 0;
}
```

---

## 🧭 Buenas prácticas

* **Prefija** los enumeradores (`MENU_`, `LOG_`, `PERM_`) para evitar colisiones de nombres.
* Define un **sentinela** cuando necesites contar/validar (`DIA_COUNT`, `ESTADO_MAX`).
* Evita depender del **valor numérico** exacto salvo que sea parte del protocolo/formato.
* Si el enum se serializa/expone, **documenta los valores** y mantén compatibilidad.

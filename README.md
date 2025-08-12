# 📚 Curso de Introducción a C

Este repositorio contiene los ejercicios y proyectos realizados durante mi curso de introducción al lenguaje **C**, ejecutado en macOS usando **VSCode** como editor.

---

## 🚀 Contenido

- `helloWorld.c` → Primer programa en C.
- Más ejercicios se irán agregando conforme avance el curso.

---

## 🧠 Recordatorio de Tipos de Datos en C

| Tipo         | Tamaño aprox. (bytes) | Rango / Ejemplo                       |
|--------------|----------------------|----------------------------------------|
| `int`        | 4                    | Enteros: -2,147,483,648 a 2,147,483,647 |
| `float`      | 4                    | Decimales: 3.14, -0.56                 |
| `double`     | 8                    | Decimales más precisos: 3.14159265     |
| `char`       | 1                    | Un solo carácter: 'A', 'b', '7'        |
| `short`      | 2                    | Enteros pequeños: -32,768 a 32,767     |
| `long`       | 8                    | Enteros grandes                        |
| `_Bool`      | 1                    | Booleanos: 0 (false), 1 (true)         |

---

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

---

## 📄 Licencia

Este proyecto está bajo la licencia MIT.

---

## ✍🏼 Créditos 

- Curso de Introducción a C by [Platzi](https://platzi.com/)

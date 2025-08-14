#include <stdio.h>

enum weekDays {
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
};

int main() {
    enum weekDays today;
    today = DOMINGO;
    printf("Day: %d", today+1);
    return 0;
}


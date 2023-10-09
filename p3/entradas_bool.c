#include <stdio.h>
#include <stdbool.h>

bool pedir_booleano(char name) {
    bool b;
    int b_aux;

    printf("Ingrese un booleano (0 o 1) para la variable %c: ", name);
    scanf("%d", &b_aux);

    b = b_aux;

    return b;
}

void imprimir_booleano(char name, bool x) {
    char* value;
    if (x) {
        value = "verdadero";
    }
    else if (!x) {
        value = "falso";
    }

    printf("El valor de verdad de %c es %s\n", name, value);
}

int main(void) {
    bool b;
    char name;

    name = 'b';
    b = pedir_booleano(name);
    imprimir_booleano(name,b);

    return 0;
}

/*
Ejemplos de ejecucion:
Ingrese un booleano (0 o 1) para la variable b: 0
El valor de verdad de b es falso

Ingrese un booleano (0 o 1) para la variable b: 1
El valor de verdad de b es verdadero
*/
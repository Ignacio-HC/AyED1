#include <stdio.h>
#include <stdbool.h>

int pedir_char() {
    char c;
    printf("Ingrese un caracter: ");
    scanf("%c",&c);

    return c;
}

bool es_vocal(char letra) {
    bool res;

    // calculo e inicializo res
    if (letra == 'a' || letra == 'e'||letra == 'i'||letra == 'o'||letra == 'u'||letra == 'A' || letra == 'E'||letra == 'I'||letra == 'O'||letra == 'U') {
        res = true;
    }  
    else {
        res = false;
    }

    // devuelvo res
    return res;
}

int main(void) {
    bool res;
    char c;
    // pido un caracter al usuario (creo estado inicial)
    c = pedir_char();
    // evaluo y muestro el resultado
    res = es_vocal(c);

    if (res) {
        printf("El caracter %c si es vocal\n", c);
    }
    else if (!res) {
        printf("El caracter %c no es vocal\n", c);
    }
    return 0;
}
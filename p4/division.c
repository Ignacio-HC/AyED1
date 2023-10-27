#include <stdio.h>
#include <assert.h>

int pedir_entero(char name) {
    int n;

    printf("Ingrese un entero para la variable %c: ", name);
    scanf("%d",&n);

    return n;
}

struct div_t {
    int cociente;
    int resto;
};

struct div_t division(int x, int y) {
    struct div_t res;
    // hago la division y guardo los valores pertinentes en res
    res.cociente = x/y;
    res.resto = x%y;

    return res;
}

int main(void) {
    int x,y;

    // pido estado inicial
    x = pedir_entero('x');
    y = pedir_entero('y');

    // checkeo precondicion pertinente y muestro error personalizado
    if (y==0) {
        printf("Error, el divisor no puede ser nulo!");
    }
    else if (y!=0) {
        struct div_t res = division(x,y);
        printf("El cociente de la division es %d\n", res.cociente);
        printf("El resto de la division es %d\n", res.resto);
    }
    return 0;
}
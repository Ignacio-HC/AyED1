#include <stdio.h>
#include <stdbool.h>

int pedirEntero(char c) {
    int n;

    printf("Ingrese un entero para %c: ", c);
    scanf("%d", &n);

    return n;
}

bool es_divisor(int x, int y) {
    bool res;

    res = (x % y == 0);

    return res;
}

bool existe_divisor(int a, int b) {
    bool res = false;
    int i = a;
    while (i < b) {
        res = res || es_divisor(b, i);
        i=i+1;
    } 

    return res;
}

bool esPrimo(int x) {
    bool res;

    res = x > 0 && !(existe_divisor(2,x));

    return res;
}

int nesimo_primo(int N) {
    int i,c;
    c = 0;
    i = 2;

    while (c < N) {
        if (esPrimo(i)) {
            c = c + 1;
        }
        
        i=i+1;
    }

    return i-1;
}

int main(void) {
    int n;
    int res;

    n = pedirEntero('n');

    while (n<=0) {
        printf("El numero ingresado debe ser positivo y no nulo!\n");
        n = pedirEntero('n');
    }

    res = nesimo_primo(n);

    printf("El %d-esimo primo es: %d\n", n, res);

    return 0;
}
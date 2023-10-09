#include <stdio.h>

int main(void) {
    int x;
    printf("Ingrese un valor para x: ");
    scanf("%d", &x);
    printf("σ0: (x -> %d)\n", x);
    x = 5;
    printf("σ1: (x -> %d)\n", x);
    return 0;
}

/*
Ejemplos de ejecuciones:
σ0: (x -> 10)
σ1: (x -> 5)

σ0: (x -> 3)
σ1: (x -> 5)

σ0: (x -> 6)
σ1: (x -> 5)
*/
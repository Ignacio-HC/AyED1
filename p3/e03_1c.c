#include <stdio.h>

int main(void) {
    int x;
    int y;
    printf("Ingrese un valor para x: ");
    scanf("%d", &x);
    printf("Ingrese un valor para y: ");
    scanf("%d", &y);
    printf("σ0: (x -> %d, y -> %d)\n", x,y);
    x = x + y;
    printf("σ1: (x -> %d, y -> %d)\n", x,y);
    y = x + y;
    printf("σ2: (x -> %d, y -> %d)\n", x,y);
    
    return 0;
}

/*
Ejemplos de ejecuciones:
σ0: (x -> 2, y -> 5)
σ1: (x -> 7, y -> 5)
σ2: (x -> 7, y -> 12)

σ0: (x -> 8, y -> 30)
σ1: (x -> 38, y -> 30)
σ2: (x -> 38, y -> 68)

σ0: (x -> 1, y -> 4)
σ1: (x -> 5, y -> 4)
σ2: (x -> 5, y -> 9)
*/
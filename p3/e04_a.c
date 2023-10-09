#include <stdio.h>
#include <stdbool.h>

int main(void) {
    // Declaraciones
    int x;
    int y;
    // inicializaciones
    printf("Ingrese un valor para X: ");
    scanf("%d", &x);
    printf("Ingrese un valor para Y: ");
    scanf("%d", &y);
    printf("σ0: (x -> %d, y -> %d)\n", x,y);
    if (x<=y) {
        x = 0; 
    }
    else if (x>=y) {
        x = 2;
    }
    printf("σ1: (x -> %d, y -> %d)\n", x,y);
    return 0;
}

/*
Ejemplos de ejecuciones:
σ0: (x -> 3, y -> 2)
σ1: (x -> 2, y -> 2)

σ0: (x -> 4, y -> 6)
σ1: (x -> 0, y -> 6)

σ0: (x -> 2, y -> 2)
σ1: (x -> 0, y -> 2)
*/
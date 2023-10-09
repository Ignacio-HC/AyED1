#include <stdio.h>

int main(void) {
    // Declaraciones
    int x;
    int y;
    int z;
    int m;
    // inicializaciones
    printf("Ingrese un valor para X: ");
    scanf("%d", &x);
    printf("Ingrese un valor para Y: ");
    scanf("%d", &y);
    printf("Ingrese un valor para Z: ");
    scanf("%d", &z);
    printf("Ingrese un valor para M: ");
    scanf("%d", &m);

    printf("σ0: (x -> %d, y -> %d, z -> %d, m -> %d)\n", x,y,z,m);
    if (x<y) {
        m = x;
    }
    else if (x>=y) {
        m = y;
    }
    printf("σ1: (x -> %d, y -> %d, z -> %d, m -> %d)\n", x,y,z,m);

    if (m<z) {}
    else if (m>=z) {
        m = z;
    }
    printf("σ2: (x -> %d, y -> %d, z -> %d, m -> %d)\n", x,y,z,m);

    return 0;
}

/*
Ejemplos de ejecuciones:
σ0: (x -> 5, y -> 4, z -> 8, m -> 0)
σ1: (x -> 5, y -> 4, z -> 8, m -> 4)
σ2: (x -> 5, y -> 4, z -> 8, m -> 4)

σ0: (x -> 9, y -> 3, z -> 5, m -> 2)
σ1: (x -> 9, y -> 3, z -> 5, m -> 3)
σ2: (x -> 9, y -> 3, z -> 5, m -> 3)
*/

/*
Que hace este programa?
RTA: Dados cuatro enteros este programa calcula el maximo entre los cuatro, y este es el valor final de la variable m.
*/
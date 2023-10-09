#include <stdio.h>

int main(void) {
    int x;
    int y;
    int i;
    int c;

    printf("Ingrese un valor para X:");
    scanf("%d",&x);
    printf("Ingrese un valor para Y:");
    scanf("%d",&y);
    printf("Ingrese un valor para i:");
    scanf("%d",&i);

    printf("σ0: (x -> %d, y -> %d, i -> %d)\n",x,y,i);
    
    i = 0;
    c = 0;
    while(x>=y) {
        c = c+1;
        x = x-y;
        i = i+1;
        printf("Iteracion %d: ", c);
        printf("\nσ1%d: (x -> %d, y -> %d, i -> %d)\n",c,x,y,i);
    }
    printf("σ2: (x -> %d, y -> %d, i -> %d)\n",x,y,i);

    return 0;
}

/*
Ejemplos de ejecucion:
σ0: (x -> 13, y -> 3, i -> 0)
Iteracion 1: 
σ11: (x -> 10, y -> 3, i -> 1)
Iteracion 2: 
σ12: (x -> 7, y -> 3, i -> 2)
Iteracion 3: 
σ13: (x -> 4, y -> 3, i -> 3)
Iteracion 4: 
σ14: (x -> 1, y -> 3, i -> 4)
σ2: (x -> 1, y -> 3, i -> 4)

σ0: (x -> 3, y -> 13, i -> 2)
σ2: (x -> 3, y -> 13, i -> 0)
*/

/*
3)
Este programa hace una division entera, y guarda en i el cociente y en x el resto.
*/
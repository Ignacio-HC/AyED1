#include <stdio.h>

int main(void) {
    int i;
    int c;
    printf("Ingrese un valor para i: ");
    scanf("%d", &i);
    
    printf("σ0: (i -> %d)\n", i);
    c=0;
    while (i!=0) {
        c = c+1;
        printf("σ1%d: (i -> %d)\n", c,i);
        i = 0;
        printf("σ2%d: (i -> %d)\n", c,i);
    }

    printf("σ3: (i -> %d)\n", i);
    
    return 0;
}
/*
Ejemplos de ejecucion:
σ0: (i -> 400)
σ1400: (i -> 400)
σ20: (i -> 0)
σ3: (i -> 0)

σ0: (i -> 1000)
σ11000: (i -> 1000)
σ20: (i -> 0)
σ3: (i -> 0)

σ0: (i -> 0)
σ3: (i -> 0)
*/
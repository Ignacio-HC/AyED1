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
        i = i-1;
        printf("σ2%d: (i -> %d)\n", c,i);
    }

    printf("σ3: (i -> %d)\n", i);
    
    return 0;
}
/*
Ejemplos de ejecucion:
σ0: (i -> 4)
σ14: (i -> 4)
σ23: (i -> 3)
σ13: (i -> 3)
σ22: (i -> 2)
σ12: (i -> 2)
σ21: (i -> 1)
σ11: (i -> 1)
σ20: (i -> 0)
σ3: (i -> 0)

σ0: (i -> 6)
σ16: (i -> 6)
σ25: (i -> 5)
σ15: (i -> 5)
σ24: (i -> 4)
σ14: (i -> 4)
σ23: (i -> 3)
σ13: (i -> 3)
σ22: (i -> 2)
σ12: (i -> 2)
σ21: (i -> 1)
σ11: (i -> 1)
σ20: (i -> 0)
σ3: (i -> 0)
*/
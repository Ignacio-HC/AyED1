#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int x;
    int i;
    bool res;
    int res_aux;
    int c;

    printf("Ingrese un valor para X:");
    scanf("%d",&x);
    printf("Ingrese un valor para i:");
    scanf("%d",&i);    
    printf("Ingrese un valor para res (0 o 1):");
    scanf("%d",&res_aux);
    res = res_aux;
    
    printf("σ0: (x -> %d, i -> %d, res -> %d)\n",x,i,res_aux);
    
    i = 2;
    res = true;
    c = 0;
    while(i<x && res) {
        c = c+1;
        res = res && (x%i != 0);
        res_aux = res;
        i = i+1;
        printf("Iteracion %d: ", c);
        printf("\nσ1%d: (x -> %d, i -> %d, res -> %d)\n",c,x,i,res_aux);
    }
    printf("σ2: (x -> %d, i -> %d, res -> %d)\n",x,i,res_aux);

    return 0;
}

/*
Ejemplos de ejecucion:
σ0: (x -> 5, i -> 0, res -> 0)
Iteracion 1: 
σ11: (x -> 5, i -> 3, res -> 1)
Iteracion 2: 
σ12: (x -> 5, i -> 4, res -> 1)
Iteracion 3: 
σ13: (x -> 5, i -> 5, res -> 1)
σ2: (x -> 5, i -> 5, res -> 1)

σ0: (x -> 9, i -> 2, res -> 0)
Iteracion 1: 
σ11: (x -> 9, i -> 3, res -> 1)
Iteracion 2: 
σ12: (x -> 9, i -> 4, res -> 0)
σ2: (x -> 9, i -> 4, res -> 0)
*/

/*
3)
RTA: Esta funcion Devuele el valor de verdad de si un entero x ingresado por tecado es primo o no y lo guarda en la variable res.
*/
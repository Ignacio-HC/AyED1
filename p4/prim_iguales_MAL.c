#include <stdio.h>
#include <stdbool.h>

#define N 5

int pedir_entero(char name) {
    int n;

    printf("Ingrese un entero para la variable %c: ", name);
    scanf("%d",&n);

    return n;
}

bool es_divisor(int x, int y) {
    bool res;

    res = (x % y == 0);

    return res;
}

bool existe_divisor(int x) {
    bool res = false;
    int i = 2;
    while (i < x) {
        res = res || es_divisor(x, i);
        i=i+1;
    } 

    return res;
}

bool esPrimo(int x) {
    bool res;

    res = x > 0 && !(existe_divisor(x));

    return res;
}

void pedir_arreglo(int n_max, int a[]) {
    int i = 0;
    int elem;
    while (i<n_max) {
        printf("Ingrese el %d-esimo elemento del arreglo: ", i+1);
        scanf("%d", &elem);
        a[i] = elem;
        i=i+1;
    }
}

// ESTA MAL, LA CONSIGNA PEDIA ALGO MUCHISIMO MAS SIMPLE: EL TAMA;O DEL TRAMO INICIAL MAS LARGO DONDE LOS ELEM SON IGUALES
int prim_iguales(int tam, int a[]) {
    int max_long, c, i;
    max_long = 0;
    c = 0;
    i = 0;

    while (i < tam-1) {
        // veo si el elemento en el que estoy parado es primo
        if (esPrimo(a[i])) {
            // en caso de serlo debo agregar uno al contador de primos
            c = c + 1;
             // checkeo si es el tramo mas grande
            if (c >= max_long) {
                // registro el nuevo tramo mas grande
                max_long = c;
            }
            // veo si el siguiente elemento del arreglo es igual al actual
            if ((a[i] != a[i+1])) {
                // si no lo es entonces debo resetear el contador de primos iguales
                c = 0;    
            }
            else {
                // debo ver 2 casos, si el siguiente elem es el ultimo elem o si no lo es
                if (i+1 == tam-1) { // caso extremo (el ultimo tramo es el mas grande) puede suceder cuando (a[i+1] es el ultimo elemento del arreglo)
                    // si lo es, entonces debo agregar 2 a mi contador porque ya no se repetira el ciclo como para contar ese primo y me dara como resultado una longitud menor de la esperada
                    c = c + 1;
                    // checkeo si es el tramo mas grande
                    if (c >= max_long) {
                        // registro el nuevo tramo mas grande
                        max_long = c;
                    }
                }
            }
        }
        // sigo recorriendo el arreglo
        i=i+1;
    }
    
    return max_long;
}

int main(void) {
    int a[N];
    int res;
    // pido estado inicial
    pedir_arreglo(N,a);

    // calculo
    res = prim_iguales(N,a);
    // muestro resultado
    printf("el tramo mas grande con primos iguales es de %d elementos\n", res);

    return 0;
}
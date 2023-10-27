#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define N 6

int pedir_entero(char name) {
    int n;

    printf("Ingrese un entero para la variable %c: ", name);
    scanf("%d",&n);

    return n;
}

bool todos_pares(int tam, int a[]) {
    bool res = true;
    int i = 0;

    while (i<tam)
    {
        res = res && ((a[i] % 2)==0);
        i = i+1;
    }
    return res;
}

bool existe_multiplo(int m, int tam, int a[]) {
    bool res = false;
    int i = 0;

    while (i<tam)
    {
        res = res || ((a[i] % m)==0);
        i = i+1;
    }
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

int main(void) {
    int a[N];
    int opcion;
    // pido los elementos del arreglo
    pedir_arreglo(N,a);

    // menu de ejecucion
    printf("Elija que funcion ejecutar\n");
    printf("Ingrese (1) si quiere ver si todos los elementos son pares\n");
    printf("Ingrese (2) si quiere ver si todos los elementos son multiplos de algun numero\n");
    scanf("%d",&opcion);
    assert((opcion == 1 || opcion == 2));
    // ejecuto el S segun la opcion elegida
    if (opcion == 1) {
        // ejecuto todos_pares
        bool res = todos_pares(N,a);
        
        // muestro resultado
        if (res) {
            printf("Todos los elementos son pares!\n");
        }
        else if (!res) {
            printf("Hay elementos impares...\n");
        }
    }
    else if (opcion == 2) {
        int m = pedir_entero('m');
        // calculo res
        bool res = existe_multiplo(m, N, a);
        // muestro resultado
        if (res) {
            printf("Hay elementos multiplos de %d!\n",m);
        }
        else if (!res) {
            printf("No hay elementos multiplos de %d...\n",m);
        }
    }
    return 0;
}
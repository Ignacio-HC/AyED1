#include <stdio.h>
#include <stdbool.h>
#define N 2

typedef char clave_t;
typedef int valor_t;

typedef struct {
    clave_t clave;
    valor_t valor;
} asoc;

void pedir_arreglo(int n_max, asoc a[]) {
    int i;
    i = 0;

    while (i<n_max) {
        printf("Ingrese la clave (caracter) del %d-esimo elemento del arreglo: ", i+1);
        scanf(" %c", &(a[i].clave));
        
        printf("Ingrese el valor (entero) del %d-esimo elemento del arreglo: ", i+1);
        scanf("%d", &(a[i].valor));
        
        i=i+1;
    }
}

bool asoc_existe(int tam, asoc a[], clave_t c) {
    bool res;
    res = false;

    int i;
    i = 0;

    while (i<tam)
    {
        res =  res || a[i].clave == c;
        i=i+1;
    }

    return res;
}

int main(void) {
    asoc a[N];
    bool res;
    char clave;

    // pido arreglo y clave a buscar
    pedir_arreglo(N,a);

    printf("Ingrese la clave que desea buscar en el arreglo: ");
    scanf(" %c", &clave);

    // calculo res y muestro por pantalla
    res = asoc_existe(N,a,clave);

    if (res) {
        printf("La clave ingresada SI existe en el arreglo provisto!\n");
    }
    else {
        printf("La clave ingresada NO existe en el arreglo provisto!\n");
    }

    return 0;
}
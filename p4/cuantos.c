#include <stdio.h>
#define N 5

typedef struct {
    int menores;
    int mayores;
    int iguales;
} comp_t;

comp_t cuantos(int tam,int a[], int elem) {
    comp_t res;
    int i;

    i = 0;
    res.iguales = 0;
    res.mayores = 0;
    res.menores = 0;
    
    while (i<tam){
        if (a[i]<elem) {
            res.menores = res.menores + 1;
        }
        else if (a[i]>elem) {
            res.mayores = res.mayores + 1;
        }
        else {
            res.iguales = res.iguales + 1;
        }
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
    int elem;

    pedir_arreglo(N, a);

    printf("Ingrese un elemento para comparar: ");
    scanf("%d", &elem);
    
    // calcular y guardar resultado
    comp_t res = cuantos(N,a,elem);

    printf("La cantidad de elementos mayores a %d es %d\n",elem, res.mayores);
    printf("La cantidad de elementos menores a %d es %d\n",elem, res.menores);
    printf("La cantidad de elementos iguales a %d es %d\n",elem, res.iguales);

    return 0;
}
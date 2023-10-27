#include <stdio.h>
#include <assert.h>

int pedir_entero(char name) {
    int n;

    printf("Ingrese un entero para la variable %c: ", name);
    scanf("%d",&n);

    return n;
}

void imprimir_hola(void) {
    printf("hola\n");
}

void hola_hasta(int n) {
    int i;
    i = 0;
    while (i<n) {
        imprimir_hola();
        i = i+1;
    }
}
int main(void) {
    int n;
    char name = 'n';

    n = pedir_entero(name);
    assert(n>0);
    
    hola_hasta(n);
    return 0;
}
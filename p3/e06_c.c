#include <stdio.h>

int pedir_entero(char name) {
    int n;

    printf("Ingrese un entero para la variable %c: ", name);
    scanf("%d",&n);

    return n;
}

void imprimir_entero(char name, int x) {
    printf("el valor del entero %c es: %d\n",name,x);
}

int main(void) {
    // Declaraciones
    int x;
    int y;
    int z;
    int m;

    char x_name = 'x';
    char y_name = 'y';
    char z_name = 'z';
    char m_name = 'm';

    // inicializaciones utilizando las nuevas funciones
    x = pedir_entero(x_name);
    y = pedir_entero(y_name);
    z = pedir_entero(z_name);
    m = pedir_entero(m_name);

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
    
    // muestro los resultados en pantalla utilizando las nuevas funciones
    imprimir_entero(x_name,x);
    imprimir_entero(y_name,y);
    imprimir_entero(z_name,z);
    imprimir_entero(m_name,m);

    return 0;
}

/*
Una ventaja de usar las nuevas funciones es que hay un menor margen de error al pedir y mostrar un entero.
Otra ventaja podria ser la claridad a la hora de leer el codigo, ya que se reducen las lineas de codigo para hacer exactamente lo mismo y por el nombre de la funcion es mas facil darse cuenta de que esta haciendo el programa esos momentos.
Si, podria escribir otra funcion (por ej. "int max(int x, int y)") que devuelva el maximo entre 2 enteros.
Podria utilizarla en los programas: 
4b:

en vez de:
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
haria:

int max(int a, int b) {
    int m;

    if (a < b) {
        m = b;
    }
    else if (a>=b) {
        m = a;
    }
    return m;
}

y para calcular el maximo entre cuatro enteros haria:
int m;
m = max(max(x,y),max(z,m));

algunos ejercicios en donde podria reutilizar imprimir_entero(char name, int n):
- en todos podriamos utilizarlo para mostrar el estado donde querramos, pasandole el nombre y el valor de la variable que querramos mostrar;
algunos ejercicios donde podriamos reutilizar pedir_entero(char name):
- en todos podriamos utilizarlo para pedir el valor de las variables correspondientes al estado inicial.
*/
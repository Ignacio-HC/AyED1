#include <stdio.h>
#include <stdbool.h>

int main(void) {
    // Declaraciones
    int x;
    int y;
    int z;
    
    int b_aux;
    int w_aux;
    bool b;
    bool w;

    // Inicializaciones (se le piden al usuario)
    printf("Hola :)\n");
    printf("Ingrese un valor para la variable x: ");
    scanf("%d", &x);
    printf("Ingrese un valor para la variable y: ");
    scanf("%d", &y);
    printf("Ingrese un valor para la variable z: ");
    scanf("%d", &z);
    printf("Ingrese un valor para la variable b (0 o 1): ");
    scanf("%d", &b_aux);
    b = b_aux;
    printf("Ingrese un valor para la variable w (0 o 1): ");
    scanf("%d", &w_aux);
    w = w_aux;
    
    // expresiones
    bool e1 = x % 4 == 0;
    int e1_aux = e1;
    bool e2 = x + y == 0 && y - x == (-1) * z;
    int e2_aux = e2;
    bool e3 = !b && w;
    int e3_aux = e3;
    
    // resultados en pantalla
    printf("\n(x -> %d, y -> %d, z -> %d, b -> %d, w -> %d)\n",x,y,z,b_aux,w_aux);
    printf("x %% 4 == 0 = %d\n", e1_aux);
    printf("x + y == 0 && y - x == (-1) * z = %d\n", e2_aux);
    printf("not b && w = %d\n", e3_aux);

    return 0;
}

/*
Un estado posible para conseguir dichos resultados es:
(x -> 8, y -> -8, z -> 16, b -> 0, w -> 0)
x % 4 == 0 = 1
x + y == 0 && y - x == (-1) * z = 1
not b && w = 0
*/
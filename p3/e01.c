#include <stdio.h>

int main(void) {
    // Declaraciones
    int x;
    int y;
    int z;
    // Inicializaciones (se le piden al usuario)
    printf("Hola :)\n");
    printf("Ingrese un valor para la variable x: ");
    scanf("%d", &x);
    printf("Ingrese un valor para la variable y: ");
    scanf("%d", &y);
    printf("Ingrese un valor para la variable z: ");
    scanf("%d", &z);
    // expresiones
    int e1 = x + y + 1;
    int e2 = z * z + y * 45 - 15 * x;
    int e3 = y - 2 == (x * 3 + 1) % 5;
    int e4 = y / 2 * x;
    int e5 = y < x * z;
    // resultados en pantalla
    printf("\n(x -> %d, y -> %d, z -> %d)\n",x,y,z);
    printf("x + y + 1 = %d\n", e1);
    printf("z * z + y * 45 - 15 * x = %d\n", e2);
    printf("y - 2 == (x * 3 + 1) %% 5 = %d\n", e3);
    printf("y / 2 * x = %d\n", e4);
    printf("y < x * z = %d\n", e5);

    return 0;
}

/*
    Resultados para los estados dados:
    
    (x -> 7, y -> 3, z -> 5)
    x + y + 1 = 11
    z * z + y * 45 - 15 * x = 55
    y - 2 == (x * 3 + 1) % 5 = 0
    y / 2 * x = 7
    y < x * z = 1

    (x -> 1, y -> 10, z -> 8)
    x + y + 1 = 12
    z * z + y * 45 - 15 * x = 499
    y - 2 == (x * 3 + 1) % 5 = 0
    y / 2 * x = 5
    y < x * z = 0
*/

/*
    ¿En la ´ultima expresi´on, que tipo tiene el resultado en lenguaje “C”?
    Rta: En la ultima expresion es de tipo Bool, sin embargo el resultado guardado como Int ya que no hay booleanos en C, False es representado por 0 y True por cualquier otro entero.
*/
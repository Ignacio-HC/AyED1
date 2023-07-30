// 1 
// a)
// 2
// b) 3
// c) 3
// d) 1

#include <stdio.h>
#include <assert.h>

int pedirEntero(char c)
{
    int x;
    printf("Ingrese un numero %c: ", c);
    scanf("%d", &x);
    return x;
}

void imprimeEntero(int x)
{
    printf("%d\n", x);
}


int main(void) {
    // inicializamos las variables
    int x,y,z,xaux,yaux,zaux,xInput,yInput,zInput;
    
    // pedimos los valores
    xInput = pedirEntero('x');
    yInput = pedirEntero('y');
    zInput = pedirEntero('z');

    x=xInput;
    y=yInput;
    z=zInput;
    // guardamos los valores originales
    xaux = x;
    yaux = y;
    zaux = z;

    // verificar precondicion
    assert(x==xaux && y==yaux && z==zaux && yaux>xaux && xaux>0);
    if (x>=y) {
        x = yaux;
        y = zaux+xaux;
        z = xaux/yaux;
    }
    if (x<y) {
        x = yaux;
        y = zaux+yaux;
        z = yaux/xaux;
    }
    //verificar postcondicion
    assert((xaux>=yaux && (x==yaux && y == zaux+xaux && z==xaux/yaux)) || (xaux<yaux && (x==yaux && y==zaux+yaux && z==yaux/xaux )));

    printf("El valor final de x es: ");
    imprimeEntero(x);
    
    printf("El valor final de y es: ");
    imprimeEntero(y);
    
    printf("El valor final de z es: ");
    imprimeEntero(z);

    return 0;
}

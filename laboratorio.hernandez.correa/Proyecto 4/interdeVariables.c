#include <stdio.h>
int main(void)
{
    int x, y, z;
    printf("Ingrese un valor para x\n");
    scanf("%d", &x);
    printf("Ingrese un valor para y\n");
    scanf("%d", &y);
    printf("Ingrese un valor para z\n");
    scanf("%d", &z);

    z = x;
    x = y;
    y = z;

    printf("El nuevo valor de x es %d\n", x);
    printf("El nuevo valor de y es %d\n", y);
    printf("El nuevo valor de z es %d\n", z);

    return 0;
}

/*
DERIVACIÓN CON FORMALISMO

{ P: x=X ∧ y=Y }
z := x ;                 | S1
x := y ;                 | S2
y := z                   | S3
{ Q: x=Y ∧ y=X }

{P}S1;S2;S3{Q}
    ≡ { verificación por precondición más débil de concatenación }
P ⇒ wp.(S1;(S2;S3)).Q
    ≡ { precondición más débil de concatenación }
P ⇒ wp.S1.(wp.(S2;S3).Q)
    ≡ { precondición más débil de concatenación }
P ⇒ wp.S1.(wp.S2.(wp.S3.Q))
    ≡ { precondición más débil de asignación }
P ⇒ wp.S1.(wp.S2.(x=Y ∧ y=X)(y←z))
    ≡ { aplico substitución }
P ⇒ wp.S1.(wp.S2.(x=Y ∧ z=X))
    ≡ { precondición más débil de asignación }
P ⇒ wp.S1.((x=Y ∧ z=X)(x←y)
    ≡ { aplico substitución }
P ⇒ wp.S1.(y=Y ∧ z=X)
    ≡ { precondición más débil de asignación }
P ⇒ (y=Y ∧ z=X)(z←x)
    ≡ { aplico substitución }
P ⇒ (y=Y ∧ x=X)
    ≡ { lógica }
True

*/

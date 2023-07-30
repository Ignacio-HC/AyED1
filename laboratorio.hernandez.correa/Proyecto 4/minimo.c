#include <stdio.h>
int main(void)
{
   int x, y;
   printf("Ingrese un valor x\n");
   scanf("%d", &x);
   printf("Ingrese un valor y\n");
   scanf("%d", &y);
   if (x < y)
   {
      printf("El minimo es %d\n", x);
   }
   else if (x == y)
   {
      printf("No hay minimo\n");
   }
   else
   {
      printf("El minimo es %d", y);
   }
}

/* Especificación y derivación mínimo entre dos valores.
Var x,r: Int;
Const X,Y: Int;
{P: x=X ∧ y=Y}
r:= x            (vamos a probar con esta asignación)
{Q: r=min.X.Y}

Demostración: P -> wp.(r:=x).(r=min.X.Y)
Supongamos x=X ∧ y=Y
wp.(r:=x).(r=min.X.Y)
={def wp}
x = min.X.Y
={por sup}
x = min.x.y
={aritmetica}
x ≤ y
No puedo probar que es True, si en la suposición tuviera que x=X ∧ y=Y ∧ x≤y entonces por la misma sup seria True.

luego implementando if tenemos:
{P: x=X ∧ y=Y}
if (x≤y) ->
   {P ∧ x≤y}
   r:= x;
   {Q}
▢  x>y ->
   {P ∧ x>y}
   r:= E;
   {Q}
fi
{Q: r=min.X.Y}

Coma la primera guarda ya esta probado resta probar la segunda.
Demostración: P ∧ x>y -> wp.(r:=E).(r=min.X.Y)
Supongamos x=X ∧ y=Y ∧ x>y
wp.(r:=E).(r=min.X.Y)
={def wp}
x = min.X.Y
={por sup}
x = min.x.y
={aritmetica y propiedad de mínimo}
(E=x ∧ x≤y) V (E=y ∧ y≤x)
={aritmetica, sup y neutro ∧}
(E=x ∧ x≤y) V E=y
={hago E=y}
(E=x ∧ x≤y) V y=y
={aritmetica, absorvente v}
True

------------------------------------------
por lo tanto el programa final queda:

Var x,r: Int;
Const X,Y: Int;

{P: x=X ∧ y=Y}

if (x≤y) ->
   r:= x;
▢  x>y ->
   r:= y;
fi

*/
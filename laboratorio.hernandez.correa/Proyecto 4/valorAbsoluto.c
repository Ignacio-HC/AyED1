#include <stdio.h>
int main(void)
{
    int x;
    printf("Ingrese un valor para x\n");
    scanf("%d", &x);

    if (x >= 0)
    {
        x = x;
    }
    else
    {
        x = x * (-1);
    }
    printf("El valor absoluto es %d\n", x);
    return 0;
}
/* Especificación y Derivación valor absoluto de un número.
Var x,r: Int;
{P: x=X}
r:= x            (vamos a probar con esta asignación)
{Q: r=|X|}

Demostración: P -> wp.(r:=x).(r=|X|)
Supongamos x=X
wp.(r:=x).(r=|X|)
={def wp}
x=|X|
={por sup}
x=|x|
={aritmetica}
(x=x ∧ x≥0) V (x=-x ∧ x<0)
={aritmetica}
(True ∧ x≥0) V (False ∧ x<0)
={neutro ∧, absorvente ∧}
x≥0 V False
={neutro V}
x≥0
No puedo probar que es True, si en la suposición tuviera que x=X ∧ x≥0 entonces por la misma sup seria True

luego implementando if tenemos:
{P: x=X}
if (x≥0) ->
   {P ∧ x≥0}
   r:= x;
   {Q}
▢ x<0 ->
   {P ∧ x<0}
   r:= E;
   {Q}
fi
{Q: r=|X|}

Coma la primera guarda ya esta probado resta probar la segunda.
Demostración: P ∧ x<0 -> wp.(r:=E).(r=|X|)
Supongamos x=X ∧ x<0
wp.(r:=E).(r=|X|)
={def wp}
E=|X|
={por sup}
E=|x|
={aritmetica}
(E=x ∧ x≥0) V (E=-x ∧ x<0)
={por sup}
(E=x ∧ x≥0) V (E=-x ∧ True)
={neutro ∧}
(E=x ∧ x≥0) V E=-x
={x≥0 contradice la sup x<0}
(E=x ∧ False) V E=-x
={absorvente ∧}
False V E=-x
={neutro V}
E=-x
={hago E=-x}
-x=-x
True

------------------------------------------
por lo tanto el programa final queda:

Var x,r: Int;

{P: x=X}

if (x≥0) ->
    r:= x
▢  r:= -x
fi

{Q: r=|X|}
------------------------------------------
*/
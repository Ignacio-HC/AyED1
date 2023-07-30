#include <stdio.h>
#include <stdbool.h>

void pedirArreglo(int a[], int n_max)
{

    int i;
    i = 0;
    while (i < n_max)
    {
        printf("Ingrese el elemento %d del arreglo: \n", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
}

bool existe_positivo(int a[], int tam)
{
    bool b;
    int i;
    i = 0;
    b = 0;

    while (i < tam && !b)
    {
        b = (a[i] > 0);
        i = i + 1;
    }
    return b;
}

bool todos_positivos(int a[], int tam)
{
    int i, b;
    i = 0;
    b = 1;

    while (i < tam && b)
    {
        b = (a[i] > 0);
        i = i + 1;
    }
    return b;
}
#define tam 3
int main(void)
{
    int array[tam];
    int x, opcion;
    pedirArreglo(array, tam);

    printf("Escriba 1 para verificar si existen valores positivvos. EScriba 0 para verificar que todos los valores son positivos \n");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        x = existe_positivo(array, tam);
        printf("1 es True y 0 es false, la respuesta es %d \n", x);
    }
    else
    {
        todos_positivos(array, tam);
        x = todos_positivos(array, tam);
        printf("1 es True y 0 es False, la respuesta es %d \n", x);
    }
    return 0;
}

/* Especificación y Derivación si existe algún elemento del arreglo de a que sea mayor a 0.
Const N: Int,
Var a:array[0,N) of Int;
m: Int;

{P: N ≥ 0}
S
{Q: m = < ∃i : 0 ≤ i < N : a.i > 0 >}

1)Posible invariante: reemplazo de constante por variable, N=n

{Q' : m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ N=n ∧ 0 ≤ n ≤ N }
donde I: m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N
     ¬B: N = n

2)Inicializacion:
{P: N ≥ 0}
m,n := E,F;
{I: m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N }

supongamos N ≥ 0
wp.(m,n := E,F).(I)
={por def de wp}
E = < ∃i : 0 <= i < F : a.i > 0 > ∧ 0 ≤ F ≤ N
={hago F=0}
E = < ∃i : 0 <= i < 0 : a.i < 0 > ∧ 0 ≤ 0 ≤ N
={aritmetica}
E = < ∃i : False : a.i < 0 > ∧ 0 ≤ N
={por suposición y rango vacio}
E = False ^ True
={neutro ^}
E = False
={hago E=False}
True

por lo tanto obtenemos:
{P: N ≥ 0}
m,n := False,0;
{I: m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N }

3)Finalización: Demostrar I ∧ ¬B -> Q
Supongamos m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N  ∧ N=n
Probar que m = < ∃i : 0 ≤ i < N : a.i > 0 > es True
={por suposición N=n}
m = < ∃i : 0 ≤ i < n : a.i > 0 >
={por supocisión}
True

4)Encontrar una cota: I ∧ B -> t ≥ 0
m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N ∧ N≠n
tenemos que 0 <= n <= N
={aritmetica}
0 ≤ N - n
luego t: N - n

5)Cuerpo del bucle: {I ^ B}
                    m,n :=  E, n+1;
                    {I}
supongamos m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N  ∧ N≠n
wp.(m,n :=  E, n+1).(m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N)
={def de wp}
E = < ∃i : 0 ≤ i < n+1 : a.i > 0 > ∧ 0 ≤ n+1 ≤ N)
={por suposición 0 ≤ n ≤ N vale para n+1 y netro ^}
E = < ∃i : 0 ≤ i < n+1 : a.i > 0 >
={separación de termino}
E = < ∃i : 0 ≤ i < n : a.i > 0 > V a.n > 0
={por suposición}
E = m V a.n > 0
={hago E = m V a.n > 0}
True

por lo tanto m,n :=  m V a.n > 0, n+1;

6)Demostrar que la cota es positiva: I ^ B -> t ≥ 0
supongamos  m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N  ∧ N≠n
veamos 0 <= n <= N
={aritmetica}
0 <= N - n
={por suposición}
True

7)Demostrar que la cota disminuye {I ∧ B ∧ t=T}
                                  m,n := m V a.n, n+1;
                                  {t < T}
supongamos  m = < ∃i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N  ∧ N≠n ^ N-n=T
wp.(m,n := m V a.n, n+1).(N-n < T)
={def de wp}
(N - (n + 1) < T
={por aritmetica y sup T=N-n}
N - n - 1 < N - n
={aritmetica}
-1 < 0
True

------------------------------------------
Finalmente el programa es:

Var n: Int;
Var m: Bool;
Var a:array[0,N) of Int;
Const N: Int,

{P: N ≥ 0}

m,n := False,0;
do (N ≠ n) ->
    m,n:= m V a.n > 0, n+1;
od

{Q: m = < ∃i : 0 ≤ i < N : a.i > 0 >}
------------------------------------------


----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------

Especificación y Derivacion si todos los elementos del arreglo de a que sea mayor a 0.
Const N: Int,
Var a:array[0,N) of Int;
m: Int;

{P: N ≥ 0}
S
{Q: m = < ∀i : 0 ≤ i < N : a.i > 0 >}

1)Posible invariante: reemplazo de constante por variable, N=n

{Q' : m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ N=n ∧ 0 ≤ n ≤ N }
donde I: m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N
     ¬B: N = n

2)Inicializacion:
{P: N ≥ 0}
m,n := E,F;
{I: m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N }

supongamos N ≥ 0
wp.(m,n := E,F).(I)
={por def de wp}
E = < ∀i : 0 <= i < F : a.i > 0 > ∧ 0 ≤ F ≤ N
={hago F=0}
E = < ∀i : 0 <= i < 0 : a.i < 0 > ∧ 0 ≤ 0 ≤ N
={aritmetica}
E = < ∀i : False : a.i < 0 > ∧ 0 ≤ N
={por suposición y rango vacio}
E = True ^ True
={neutro ^}
E = True
={hago E=True}
True

por lo tanto obtenemos:
{P: N ≥ 0}
m,n := True,0;
{I: m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N }

3)Finalización: Demostrar I ∧ ¬B -> Q
Supongamos m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N  ∧ N=n
Probar que m = < ∀i : 0 ≤ i < N : a.i > 0 > es True
={por suposición N=n}
m = < ∀i : 0 ≤ i < n : a.i > 0 >
={por supocisión}
True

4)Encontrar una cota: I ∧ B -> t ≥ 0
m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N ∧ N≠n
tenemos que 0 <= n <= N
={aritmetica}
0 ≤ N - n
luego t: N - n

5)Cuerpo del bucle: {I ^ B}
                    m,n :=  E, n+1;
                    {I}
supongamos m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N  ∧ N≠n
wp.(m,n :=  E, n+1).(m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N)
={def de wp}
E = < ∀i : 0 ≤ i < n+1 : a.i > 0 > ∧ 0 ≤ n+1 ≤ N)
={por suposición 0 ≤ n ≤ N vale para n+1 y netro ^}
E = < ∀i : 0 ≤ i < n+1 : a.i > 0 >
={separación de termino}
E = < ∀i : 0 ≤ i < n : a.i > 0 > V a.n > 0
={por suposición}
E = m V a.n > 0
={hago E = m V a.n > 0}
True

por lo tanto m,n :=  m V a.n > 0, n+1;

6)Demostrar que la cota es positiva: I ^ B -> t ≥ 0
supongamos  m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N  ∧ N≠n
veamos 0 <= n <= N
={aritmetica}
0 <= N - n
={por suposición}
True

7)Demostrar que la cota disminuye {I ∧ B ∧ t=T}
                                  m,n := m V a.n, n+1;
                                  {t < T}
supongamos  m = < ∀i : 0 ≤ i < n : a.i > 0 > ∧ 0 ≤ n ≤ N  ∧ N≠n ^ N-n=T
wp.(m,n := m V a.n, n+1).(N-n < T)
={def de wp}
(N - (n + 1) < T
={por aritmetica y sup T=N-n}
N - n - 1 < N - n
={aritmetica}
-1 < 0
True

------------------------------------------
Finalmente el programa es:

Var n: Int;
Var m: Bool;
Var a:array[0,N) of Int;
Const N: Int,

{P: N ≥ 0}

m,n := True,0;
do (N ≠ n) ->
    m,n:= m ∧ a.n > 0, n+1;
od

{Q: m = < ∀i : 0 ≤ i < N : a.i > 0 >}
------------------------------------------
*/

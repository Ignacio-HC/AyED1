#include <stdio.h>
#include <assert.h>
void holaHasta(int n)
{
    int i = 0;
    while (i < n)
    {
        i = i + 1;
        printf("Hola\n");
    }
}
int main(void)
{
    int n;
    printf("Ingrese un valor para n\n");
    scanf("%d", &n);
    assert(n > 0);
    holaHasta(n);
    return 0;
}
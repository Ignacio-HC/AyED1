
#include <stdio.h>
int main(void)
{
  int x, y, i;
  printf("Ingrese un valor para x\n");
  scanf("%d", &x);
  printf("Ingrese un valor para y\n");
  scanf("%d", &y);
  printf("Ingrese un valor para i\n");
  scanf("%d", &i);
  i = 0;
  while (x >= y)
  {
    x = x - y;
    i = i + 1;
  }
  printf("Estado final: x=%d, y=%d, i = %d\n", x, y, i);
  return 0;
}

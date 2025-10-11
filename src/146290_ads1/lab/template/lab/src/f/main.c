#include "fib.h"
#include <stdio.h>
int fib(int n) {
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;
  int a = 0, b = 1;
  for (int i = 2; i <= n; i++) {
    int c = a + b;
    a = b;
    b = c;
  }
  return b;
}
int main(void) {
  int n;
  if (scanf("%d", &n) != 1)
    return 1;
  printf("%d", fib(n));
  return 0;
}

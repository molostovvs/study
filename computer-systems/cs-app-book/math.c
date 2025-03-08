#include <stdio.h>

int main() {
  int x = 5 * 10 + 5 + 8 / 2;
  printf("%d\n", x);

  int a = 555 * 555 * 555 * 5;
  printf("%d\n", a);

  float z = (3.14 + 1e-20) - 1e-20;
  printf("%f\n", z);

  // 101 -> 1010
  int bitMultiply = 5 << 1; // 10
  printf("%d\n", bitMultiply);

  // 101 -> 10
  int bitDivision = 5 >> 1; // 2
  printf("%d\n", bitDivision);

  return 0;
}

#include "Base.h"

int fibonachiNormal(int n) {
	int a = 1, b = 1, c = 2;
	for (int i = 0; i < n - 2; i++){
		c = a + b;
		a = b;
		b = c;
	}

  return c;
}

int fibonachiRecursive(int n) {
	if(n <= 2) return 1;
  return fibonachiRecursive(n - 1) + fibonachiRecursive(n - 2);
}

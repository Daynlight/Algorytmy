#include "Base.h"

int fibonacciNormal(int n) {
	int a = 1, b = 1, c = 2;
	for (int i = 0; i < n - 2; i++){
		c = a + b;
		a = b;
		b = c;
	}

  return c;
}

int fibonacciRecursive(int n) {
	if(n <= 2) return 1;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

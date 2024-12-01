#include "../Base.h"

int fibonacciNormal(int n) {
	int a = 1, b = 1, c = 2;							// 3
	for (int i = 0; i < n - 2; i++){			// n - 2
		c = a + b;														// 1
		a = b;																// 1
		b = c;																// 1
	}

  return c; 														// 1
}
// 3 + (n - 2)*3 = 3(n - 1) = 3n - 3 < 3n => O(n)
// 3 + (n - 2)*3 = 3(n - 1) = 3n - 3 > 3n => Ω(n)
// θ(n)


int fibonacciRecursive(int n) {
	if(n <= 2) return 1;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
// T(n) = T(n - 1) + T(n - 2) + O(0) => O(2^n)
// T(n) = T(n - 1) + T(n - 2) + O(0) => Ω(2^n)
// θ(2^n)
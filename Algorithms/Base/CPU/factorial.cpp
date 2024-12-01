#include "../Base.h"

int factorialNormal(int n) {
  int res = n;
	for(int i = 2; i < n; i++) res *= i;
	return res;
}

int factorialRecursive(int n){
	if(n == 2) return 2;
  return n * factorialRecursive(n-1);
}
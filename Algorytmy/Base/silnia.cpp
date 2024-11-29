#include "Base.h"

int silniaNormal(int n) {
  int res = n;
	for(int i = 2; i < n; i++) res *= i;
	return res;
}

int silniaRecursive(int n){
	if(n == 2) return 2;
  return n * silniaRecursive(n-1);
}
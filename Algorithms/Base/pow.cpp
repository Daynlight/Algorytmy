#include "Base.h"

int powNormal(int a, int n){
	int res = a;
	if (n == 0) return 1;
	for (int i = 1; i < n; i++) res *= a;
	return res;
}

int powRecursive(int a, int n){
	if (n <= 0) return 1;
	return a * powRecursive(a, n - 1);
}
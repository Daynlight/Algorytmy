#include "Base.h"

int nwdRecursive(int a, int b){
	a = abs(a);
	b = abs(b);
	if (b == 0) return a;
	return nwdRecursive(b, a % b);
}

int nwdNormal(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a != b && b) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}
#include "../Base.h"

int nwdRecursive(int a, int b){
	a = abs(a);
	b = abs(b);
	if (b == 0) return a;
	return nwdRecursive(b, a % b);
}
// T(n) = T(b, a%b) + O(1)
// depends a and b min(a, b)
// T(n) = T(min(a,b)) + O(1);
// 0 = log(b)(1) = 0
// O(lg(min(a,b)))
// Ω(lg(min(a,b)))
// θ(lg(min(a,b)))


int nwdNormal(int a, int b) {
	a = abs(a);										// 1
	b = abs(b);										// 1
	while (a != b && b) {					// k pessimistic k = min(a, b) optimistic k = 0
		int temp = a % b;							// 1
		a = b;												// 1
		b = temp;											// 1	
	}

	return a;											// 1
}
// 3 + 3*min(a,b) => O(min(a,b))
// Ω(1)
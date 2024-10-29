#include "Algorytmy.h"

int Array::sumaBaseReq() {
	return sumaBaseReqFun(0);
}

int Array::sumaThreadReq() {
	return sumaThreadReqFun(0, arr.size() - 1);
}

int Array::sumaBaseReqFun(int x) {
	if (x >= arr.size()) return 0;
	return arr[x] + sumaBaseReqFun(x + 1);
}

int Array::sumaThreadReqFun(int x, int y) {
	if (y - x == 0) return arr[x];
	else if (y - x == 1) return arr[x] + arr[y];
	else if (y - x < 0) return 0;

	int a = sumaThreadReqFun(x, (y - x) / 2 + x);
	int b = sumaThreadReqFun((y - x) / 2 + x + 1, y);

	return a + b;
}

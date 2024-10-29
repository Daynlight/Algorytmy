#include "Suma.h"

Suma::Suma(){
}

Suma::Suma(std::initializer_list<int> inArr) {
	arr.reserve(inArr.size());
	for (const int el : inArr)
		arr.emplace_back(el);
}

int Suma::sumaBaseReq() {
	return sumaBaseReqFun(0);
}

int Suma::sumaBaseReqFun(int x) {
	if (x >= arr.size()) return 0;
	return arr[x] + sumaBaseReqFun(x + 1);
}

int Suma::sumaThreadReq() {
	return sumaThreadReqFun(0, arr.size() - 1);
}

size_t Suma::size() {
	return arr.size();
}

int Suma::sumaThreadReqFun(int x, int y) {
	if (y - x == 0) return arr[x];
	else if (y - x == 1) return arr[x] + arr[y];
	else if (y - x < 0) return 0;

	int a = 0, b = 0;
	if (ThreadsLevel < THREADSDEEPLEVEL) {
		std::future<int> eventA = std::async(std::launch::async, [this](int a, int b) { return sumaThreadReqFun(a, b); }, x, (y - x) / 2 + x);
		std::future<int> eventB = std::async(std::launch::async, [this](int a, int b) { return sumaThreadReqFun(a, b); }, (y - x) / 2 + x + 1, y);
		
		ThreadsLevel++;
		a = eventA.get();
		b = eventB.get();
		ThreadsLevel--;
	}
	else {
		a = sumaThreadReqFun(x, (y - x) / 2 + x);
		b = sumaThreadReqFun((y - x) / 2 + x + 1, y);
	}

	return a + b;
}


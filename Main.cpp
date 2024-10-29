#include "Algorytmy.h"

int main() {
	SumaAlgorytmy();

	return 0;
}

void SumaAlgorytmy() {
	Suma arr;

	int add =  5000000000;
	arr.reserve(add);
	for (int i = 0; i < add; i++) {
		arr.emplace_back(1);
	}
		

	printf("List Size: %d\n", arr.size());

	// Clock Test
	Time([] { _sleep(100); });

	printf("\n");

	//Time([&arr] { printf("Suma: %d\n", arr.sumaBaseReq()); });

	printf("\n");

	for (int i = 0; i < 100; i++){
		arr.THREADSDEEPLEVEL = i;
		Time([&arr] { printf("Suma: %d for %d threads ", arr.sumaThreadReq(), arr.THREADSDEEPLEVEL); });
	}
}
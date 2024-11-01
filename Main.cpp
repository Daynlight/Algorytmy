#include "Algorytmy.h"

int main() {
	SumaAlgorytmy();

	return 0;
}

void SumaAlgorytmy() {
	Array<long> arr;

	int add =  5000000000;
	arr.reserve(add);
	for (int i = 0; i < add; i++) {
		arr.emplace_back(i%10);
	}

	printf("List Size: %Id\n", arr.size());

	// Clock Test 
	printf("Clock test 100ms: ");
	Time([] { std::this_thread::sleep_for(std::chrono::milliseconds(100)); });

	printf("\n");

	Time([&arr] { printf("Suma: %d\n", arr.sumaLine<long long>()); });

	printf("\n");

	for (int i = 0; i < 100; i++){
		arr.THREADSDEEPLEVEL = i;
		Time([&arr] { printf("Suma: %Id for %d threads ", arr.sumaThreadReq<long long>(), arr.THREADSDEEPLEVEL); });
	}
}
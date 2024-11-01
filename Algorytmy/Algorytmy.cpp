#include "Algorytmy.h"

int main(){
	SumaAlgorytmy();

	return 0;
}

void SumaAlgorytmy() {
	ARRAY<int> arr;

	int add =  705032704;
	arr.reserve(add);
	for (int i = 0; i < add; i++) {
		arr.emplace_back(i%10);
	}

	printf("List Size: %ld\n", arr.size());

	// Clock Test 
	printf("Clock test 100ms: ");
	Time([] { std::this_thread::sleep_for(std::chrono::milliseconds(100)); });

	printf("\n");

	Time([&arr] { printf("Suma: %lld\n", arr.sumaLine<long long>()); });

	printf("\n");

	for (int i = 0; i < 100; i++){
		arr.THREADSDEEPLEVEL = i;
		Time([&arr] { printf("Suma: %lld for %d threads ", arr.sumaThreadReq<long long>(), arr.THREADSDEEPLEVEL); });
	};
}
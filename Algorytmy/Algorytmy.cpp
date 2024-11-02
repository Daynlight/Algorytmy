#include "Algorytmy.h"

static bool PRINT = 0;

int main(){
	CheckClock();
	SumaAlgorytmy(500000);

	return 0;
}

void CheckClock(){
	printf("\n****[Checking Clock Accuracy]****\n");
	printf("Clock test 100ms: ");
	Time([] { std::this_thread::sleep_for(std::chrono::milliseconds(100)); });
}

void SumaAlgorytmy(int elements) {
	printf("################ Suma Algorytmow ################\n");

	// [Init]
	printf("****[Create Random Array]****\n");
	ARRAY<int> arr;
	arr.reserve(elements);

	if (elements < 1000 || PRINT) {
		Time([&arr, &elements] {
			printf("[");
			for (int i = 0; i < elements; i++) {
				arr.emplace_back(Random<int>(-200, 200));
				printf("%d, ", arr[i]);
			};
			printf("\b\b]\n");
			});
		printf("List Size: %d\n", arr.size());
	}
	else {
		Time([&arr, &elements] {
			for (int i = 0; i < elements; i++)
				arr.emplace_back(Random<int>(-200, 200));
			});
		printf("List Size: %d\n", arr.size());
	}

	// [Tests]
	printf("\n****[Base Line Sum]****\n");
	Time([&arr] { printf("Suma: %lld\n", arr.LineSum<long long>()); });

	printf("\n****[Thread Half Parts Sum Req]****\n");
	std::unordered_map<int, int> compareArray;
	for (int i = 0; i < 10; i++){
		arr.THREADSDEEPLEVEL = i;
		compareArray[i] = Time([&arr] { printf("Suma: %lld for %d threads \n", arr.HalfThreadSumReq<long long>(), arr.THREADSDEEPLEVEL); });
	};
	int minTrhead = 0;
	for (auto el : compareArray)
		if (el.second < compareArray[minTrhead]) minTrhead = el.first;
	printf("Fastest for %d Threads, time: %d ns", minTrhead, compareArray[minTrhead]);
}
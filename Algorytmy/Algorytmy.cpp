#include "Algorytmy.h"

int main(){
	printf("Press to Start\n");
	scanf("Press to Start\n");

	CheckClock();
	SumaAlgorytmy(10000000);
	SortAlgorytmy(10000000);

	return 0;
}

void CheckClock(){
	printf("\n****[Checking Clock Accuracy]****\n");
	printf("Clock test 100ms: ");
	Time([] { std::this_thread::sleep_for(std::chrono::milliseconds(100)); });
}

void SumaAlgorytmy(int elements) {
	printf("\n################ Suma Algorytmow ################\n");

	ARRAY<int> arr = ArrayCreate<int>(elements);
	std::unordered_map<int, int> compareArray;
	int minTrhead = 0;

	printf("\n****[Base Line Sum]****\n");
	Time([&arr] { printf("Suma: %lld\n", arr.LineSum<long long>(0, arr.size() - 1)); });

	printf("\n****[Thread Half Parts Sum Req]****\n");
	compareArray.clear();
	minTrhead = 0;
	for (int i = 0; i < 10; i++){
		arr.THREADSDEEPLEVEL = i;
		compareArray[i] = Time([&arr] { printf("Suma: %lld for %d threads \n", arr.HalfThreadSumReq<long long>(), arr.THREADSDEEPLEVEL); });
	};
	for (auto el : compareArray)
		if (el.second < compareArray[minTrhead]) minTrhead = el.first;
	printf("Fastest for %d Threads, time: %d ns\n", minTrhead, compareArray[minTrhead]);

	printf("\n****[Thread Half And Line Sum]****\n");
	compareArray.clear();
	minTrhead = 0;
	for (int i = 0; i < 10; i++) {
		arr.THREADSDEEPLEVEL = i;
		compareArray[i] = Time([&arr] { printf("Suma: %lld for %d threads \n", arr.HalfThreadAndLineSum<long long>(), arr.THREADSDEEPLEVEL); });
	};
	for (auto el : compareArray)
		if (el.second < compareArray[minTrhead]) minTrhead = el.first;
	printf("Fastest for %d Threads, time: %d ns\n", minTrhead, compareArray[minTrhead]);
}

void SortAlgorytmy(int elements) {
	printf("\n################ Sort Algorytmow ################\n");

	ARRAY<int> arr = ArrayCreate<int>(elements);

	printf("\n****[Insertion Sort]****\n");
	ARRAY<int> arrCopy = CopyArray(arr);
	Time([&arrCopy] { arrCopy.InsertionSort(); printf("Array Sorted in "); });
	if (arrCopy.size() < 1000 || PRINT) {
		printf("[");
		for (int el : arrCopy)
			printf("%d, ", el);
		printf("\b\b]\n");
	}
}

#include "Dev.h"
#include "Base/Base.h"
#include "Arrays/Array.h"
#include "ArraysTestModels.h"

void checkClock();

int main(int args, const char *argv[]) {
	checkClock();

	// printf("armstrong numbers:\n");
	// std::vector<unsigned long long> arm;
	// std::chrono::nanoseconds time = Time([&arm]{
	// 	arm = armstrongArray(100, UINT32_MAX);
	// });

	// for(int el : arm)
	// 	printf("%d\n", el);
	// printTime(time);

	// Array<int> array;
	// array.createRandom(1000);
	// array.mergeSort(true);
	// printf("[");
	// for (int el : array)
	// 	printf("%d, ", el);
	// printf("\b\b]");

	sortTest(pow(2, 16), -200, 200);

	return 0;
}
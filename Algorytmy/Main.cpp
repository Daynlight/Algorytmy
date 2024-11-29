#include "Dev.h"
#include "Base/Base.h"

void checkClock();

int main(int args, const char *argv[]) {
	checkClock();

	printf("armstrong numbers:\n");
	std::vector<unsigned long long> arm;
	std::chrono::nanoseconds time = Time([&arm]{
		arm = armstrongArray(100, UINT32_MAX);
	});

	for(int el : arm)
		printf("%d\n", el);
	printTime(time);

	return 0;
}
#include "Dev.h"
#include "Base/Base.h"

void checkClock();

int main(int args, const char *argv[]) {
	checkClock();

	printf("armstrong numbers:\n");
	std::vector<int> arm;
	std::chrono::nanoseconds time = Time(10, [&arm]{
		arm = armstrongArray(100, 999999999, 6); });

	for(int el : arm)
		printf("%d\n", el);
	printTime(time);

	return 0;
}
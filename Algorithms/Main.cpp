#include "Dev.h"
#include "Base/Base.h"
#include "Arrays/Array.h"
#include "TestModels.h"

void checkClock();

int main(int args, const char *argv[]) {
	checkClock();

	armstrongNumbersTest(100, 999999);
	sumTest(999999, -200, 200);
	sortTest(9999, -200000, 200000);

	return 0;
}
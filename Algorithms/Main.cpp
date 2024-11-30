#include "Dev.h"
#include "Base/Base.h"
#include "Arrays/Array.h"
#include "ArraysTestModels.h"

void checkClock();

int main(int args, const char *argv[]) {
	checkClock();

	sortTest(pow(2, 16), INT_MIN, INT_MAX);

	return 0;
}
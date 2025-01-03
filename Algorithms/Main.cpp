#include "Dev.h"
#include "Base/Base.h"
#include "Arrays/Array.h"
#include "TestModels.h"

void checkClock();

int main(int args, const char *argv[]) {
	checkClock();

	sumTest(pow(2, 24), -200, 200);
	sortTest(pow(2, 16), INT_MIN, INT_MAX);

	return 0;
}
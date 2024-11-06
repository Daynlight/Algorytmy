#include "Algorytmy.h"

int main(int args, const char *argv[]) {
#ifdef NDEBUG
	std::unordered_map<char, bool> args_map;

	for (int i = 1; i < args; i++) {
		bool load = false;
		for (const char& el : std::string(argv[i])) {
			if (el == '-') load = true;
			if (load) args_map[el] = true;
		}
	}
		
	if (args_map['h']) {
		printf("c - Check clock accuracy\n");
		printf("r - Recursion\n");
		printf("n - NWD algorytms\n");
		printf("s - Show sum algorytms\n");
		printf("q - Show sort algorytms\n");
		return 0;
	}

	if (args_map['c']) checkClock();
	if (args_map['n'] && args_map['r']) {
		int a, b;
		printf("values: ");
		scanf("%d %d", &a, &b);
		printf("NWD(%d, %d) = %d", a, b, nwdRecursive(a, b));
	}
	if (args_map['n'] && !args_map['r']) {
		int a, b;
		printf("values: ");
		scanf("%d %d", &a, &b);
		printf("NWD(%d, %d) = %d", a, b, nwdNormal(a, b));
	}
	if (args_map['s']) sumaAlgorytmy(100000, -5000, 5000);
	if (args_map['q']) sortAlgorytmy(100000, -5000, 5000);
#else
	checkClock();
	nwdAlgorytmy(100000, -100000, 100000);
	sumaAlgorytmy(100000, -5000, 5000);
	sortAlgorytmy(100000, 0, 5000);
#endif

	return 0;
}
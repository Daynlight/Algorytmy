#include "Algorytmy.h"

#define NDEBUG

int main(int args, const char *argv[]) {
#ifdef NDEBUG
	std::unordered_map<std::string, std::vector<int>> argv_map; // [key] {bool, val1, val2 ...}
	std::chrono::nanoseconds time;

	std::string key = "";
	for(int i = 1; i < args; i++){
		if(argv[i][0] == '-'){
			if(argv[i][1] == '-'){
				key = argv[i];
				argv_map[key].emplace_back(1);
			}
		}
		else{
			std::stringstream strVal;
			strVal << argv[i];
			int intVal;
			strVal >> intVal;
			argv_map[key].emplace_back(intVal);
		}
	}
	
	if (argv_map.find("--help") != argv_map.end()) {
		printf("\n###################################################################\n");
		printf("############################ Algorytmy ############################\n");
		printf("###################################################################\n\n");
		printf("--clock - Check clock accuracy\n");
		printf("--nwd [a] [b] [recursive] - Print NWD value\n");
		printf("--pow [a] [n] [recursive] - Print POW value\n");
		printf("--silnia [a] [recursive] - Print Silnia value\n");
		printf("--fibonachi [n] [recursive] - Print Fibonachi n element\n");
		printf("--suma [elementy] [min] [max] - Show tests for sum algorytms\n");
		printf("--sort [elementy] [min] [max] - Show tests for sort algorytms\n");
		return 0;
	}
	if (argv_map.find("--clock") != argv_map.end()) 
		checkClock();
	if (argv_map.find("--nwd") != argv_map.end()){
		int a = argv_map["--nwd"][1];
		int b = argv_map["--nwd"][2];
		if(!argv_map["--nwd"][3]){
			 time = Time([&a, &b]{ printf("nwd(%d, %d) = %d | ", a, b, nwdNormal(a, b)); });
			 printTime(time);
		}
		else{
				time = Time([&a, &b]{ printf("nwd(%d, %d) = %d | ", a, b, nwdRecursive(a, b)); }); 
				printTime(time);
		}
	}
	if (argv_map.find("--pow") != argv_map.end()){
		int a = argv_map["--pow"][1];
		int n = argv_map["--pow"][2];
		if(!argv_map["--pow"][3]){
			time = Time([&a, &n]{ printf("%d^%d = %d | ", a, n, powNormal(a, n)); });
			printTime(time);
		}
		else{
			time = Time([&a, &n]{ printf("%d^%d = %d | ", a, n, powRecursive(a, n)); }); 
			printTime(time);
		}
	}
	if (argv_map.find("--silnia") != argv_map.end()){
		int a = argv_map["--silnia"][1];
		if(!argv_map["--silnia"][2]){
			time = Time([&a]{ printf("%d! = %d | ", a, silniaNormal(a)); });
			printTime(time);
		}
		else{
			time = Time([&a]{ printf("%d! = %d | ", a, silniaRecursive(a)); }); 
			printTime(time);
		}
	}
	if (argv_map.find("--fibonachi") != argv_map.end()){
		int n = argv_map["--fibonachi"][1];
		if(!argv_map["--fibonachi"][2]){
		time = Time([&n]{ printf("fibonachi(%d) = %d | ", n, fibonachiNormal(n)); });
		printTime(time);
		}
		else{
		time = Time([&n]{ printf("fibonachi(%d) = %d | ", n, fibonachiRecursive(n)); }); 
		printTime(time);
		}
	}
	if (argv_map.find("--suma") != argv_map.end()) 
		sumaTest(argv_map["--suma"][1], argv_map["--suma"][2], argv_map["--suma"][3]);
	if (argv_map.find("--sort") != argv_map.end()) 
		sortTest(argv_map["--sort"][1], argv_map["--sort"][2], argv_map["--sort"][3]);
#else
	checkClock();
	
	std::chrono::nanoseconds 
	time = Time([]{printf("nwd(%d, %d) = %d | ", 27, -6, nwdNormal(27, -6));});
	printTime(time);
	time = Time([]{printf("nwd(%d, %d) = %d | ", 27, -6, nwdNormal(27, -6));});
	printTime(time);
	time = Time([]{printf("%d^%d = %d | ", 2, 5, powNormal(2, 5));});
	printTime(time);
	time = Time([]{printf("%d^%d = %d | ", 2, 5, powRecursive(2, 5));});
	printTime(time);
	time = Time([]{printf("%d! = %d | ", 5, silniaNormal(5));});
	printTime(time);
	time = Time([]{printf("%d! = %d | ", 5, silniaRecursive(5));});
	printTime(time);
	time = Time([]{printf("fibonachi(%d) = %d | ", 5, fibonachiNormal(5));});
	printTime(time);
	time = Time([]{printf("fibonachi(%d) = %d | ", 5, fibonachiRecursive(5));});
	printTime(time);
			
	sumaTest(100000, -5000, 5000);
	sortTest(100000, 0, 5000);
#endif

	return 0;
}
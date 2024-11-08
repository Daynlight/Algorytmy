#include "Algorytmy.h"

#define NDEBUG

int main(int args, const char *argv[]) {
#ifdef NDEBUG
	std::vector<std::pair<std::string, std::vector<int>>> argv_map; // {[key] {val1, ...}, [key2] {val1, ...}}
	
	std::chrono::nanoseconds time;
	std::string key = "";
	int index = -1;

	for(int i = 1; i < args; i++){
		if(argv[i][0] == '-' && argv[i][1] == '-'){
			index++;
			key = argv[i];
			argv_map.emplace_back(std::pair<std::string, std::vector<int>>());
			argv_map[index].first = key;
		}
		else{
			std::stringstream strVal;
			strVal << argv[i];
			int intVal;
			strVal >> intVal;
			argv_map[index].second.emplace_back(intVal);
		}
	}
	
	for(int i = 0; i < argv_map.size(); i++){
		if (argv_map[i].first == "--help") {
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
		if (argv_map[i].first == "--clock") 
			checkClock();
		if (argv_map[i].first == "--nwd"){
			int a = argv_map[i].second[0];
			int b = argv_map[i].second[1];
			if(!argv_map[i].second[2]){
				time = Time([&a, &b]{ printf("nwd(%d, %d) = %d | ", a, b, nwdNormal(a, b)); });
				printTime(time);
			}
			else{
					time = Time([&a, &b]{ printf("nwd(%d, %d) = %d | ", a, b, nwdRecursive(a, b)); }); 
					printTime(time);
			}
		}
		if (argv_map[i].first == "--pow"){
			int a = argv_map[i].second[0];
			int n = argv_map[i].second[1];
			if(!argv_map[i].second[2]){
				time = Time([&a, &n]{ printf("%d^%d = %d | ", a, n, powNormal(a, n)); });
				printTime(time);
			}
			else{
				time = Time([&a, &n]{ printf("%d^%d = %d | ", a, n, powRecursive(a, n)); }); 
				printTime(time);
			}
		}
		if (argv_map[i].first == "--silnia"){
			int a = argv_map[i].second[0];
			if(!argv_map[i].second[1]){
				time = Time([&a]{ printf("%d! = %d | ", a, silniaNormal(a)); });
				printTime(time);
			}
			else{
				time = Time([&a]{ printf("%d! = %d | ", a, silniaRecursive(a)); }); 
				printTime(time);
			}
		}
		if (argv_map[i].first == "--fibonachi"){
			int n = argv_map[i].second[0];
			if(!argv_map[i].second[1]){
			time = Time([&n]{ printf("fibonachi(%d) = %d | ", n, fibonachiNormal(n)); });
			printTime(time);
			}
			else{
			time = Time([&n]{ printf("fibonachi(%d) = %d | ", n, fibonachiRecursive(n)); }); 
			printTime(time);
			}
		}
		if (argv_map[i].first == "--suma") 
			sumaTest(argv_map[i].second[0], argv_map[i].second[1], argv_map[i].second[2]);
		if (argv_map[i].first == "--sort")
			sortTest(argv_map[i].second[0], argv_map[i].second[1], argv_map[i].second[2]);
	}
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
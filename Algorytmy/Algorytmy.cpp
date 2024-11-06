#include "Algorytmy.h"

void checkClock(){
	printf("\n****[Checking Clock Accuracy]****\n");
	printf("Clock test 100ms: ");
	printTime(Time([] { std::this_thread::sleep_for(std::chrono::milliseconds(100)); }));
}

void nwdAlgorytmy(size_t count, int min, int max){
	printf("\n###################################################################\n");
	printf("########################## NWD Algorytmy ##########################\n");
	printf("###################################################################\n\n");

	std::unordered_map<std::string, std::chrono::nanoseconds> compare_types;

	for (size_t i = 0; i < count; i++) {
		int a = random(min, max);
		int b = random(min, max);
		int mult = random(min, max);
		b *= mult;
		int nwd = 0;

		std::chrono::nanoseconds time = Time([&nwd, &a, &b] { nwd = nwdNormal(a, b); });
		if (count < MAXPRINTSIZE || FORCEPRINT) printf("nwdNormal(%d,%d) = %d\n", a, b, nwd);
		if (count < MAXPRINTSIZE || FORCEPRINT) printTime(time);
		compare_types["nwdNormal(" + std::to_string(a) + ", " + std::to_string(b) + ")"] = time;

		time = Time([&nwd, &a, &b] { nwd = nwdRecursive(a, b); });
		if (count < MAXPRINTSIZE || FORCEPRINT) printf("nwdReqursion(%d,%d) = %d\n", a, b, nwd);
		if (count < MAXPRINTSIZE || FORCEPRINT) printTime(time);
		compare_types["nwdReqursion(" + std::to_string(a) + ", " + std::to_string(b) + ")"] = time;
	}


	printf("\n****[ Result ]****\n");
	int min_time = 0;
	std::vector<std::pair<std::string, std::chrono::nanoseconds>> compare_types_vector;
	compare_types_vector.reserve(compare_types.size());
	for (std::pair<std::string, std::chrono::nanoseconds> el : compare_types)
		compare_types_vector.emplace_back(el);
	std::sort(compare_types_vector.begin(), compare_types_vector.end(), [](auto& left, auto& right) { return left.second < right.second; });
	printf("Best time for %s with time: ", compare_types_vector[0].first.c_str());
	printTime(compare_types_vector[0].second);
}

void sumaAlgorytmy(size_t elements, int min, int max) {
	printf("\n###################################################################\n");
	printf("######################### Suma Algorytmy ##########################\n");
	printf("###################################################################\n\n");

	std::unordered_map<size_t, std::chrono::nanoseconds> compare_threads;
	std::unordered_map<std::string, std::chrono::nanoseconds> compare_types;
	size_t min_time = 0;
	int suma = 0;

	printf("****[ Create Random Array ]****\n");
	Array<int> arr;
	arr.createRandom(elements, min, max, true);

	printf("\n****[ Line Sum ]****\n");
	std::chrono::nanoseconds time = 
		Time([&arr, &suma] { suma = arr.lineSum(0, arr.size()); });
	printf("Sumed %d elements with resault %d in ", static_cast<int>(arr.size()), suma);
	printTime(time);
	compare_types["Line Sum"] = time;

	printf("\n****[ Thread Half Parts Sum Req ]****\n");
	compare_threads.clear();
	min_time = 0;
	for (int i = 0; i < 10; i++){
		compare_threads[i] = Time([&arr, &suma, &i] { suma = arr.halfThreadSumReq(i); });
		printf("Sumed %d elements with resault %d on %d threads in: ", static_cast<int>(arr.size()), suma, i);
		printTime(compare_threads[i]);
	};
	for (auto el : compare_threads)
		if (el.second < compare_threads[min_time]) min_time = el.first;
	printf("  Best time for %d threads with time: ", static_cast<int>(min_time));
	printTime(compare_threads[min_time]);
	compare_types[std::string("Thread Half Parts Sum Req with threads " + std::to_string(min_time))] = compare_threads[min_time];

	printf("\n****[ Thread Half And Line Hybrid Sum ]****\n");
	compare_threads.clear();
	min_time = 0;
	for (int i = 0; i < 10; i++) {
		compare_threads[i] = Time([&arr, &i] { arr.halfThreadAndLineSum(i); });
		printf("Sumed %d elements with resault %d on %d threads in: ", static_cast<int>(arr.size()), suma, i);
		printTime(compare_threads[i]);
	};
	for (auto el : compare_threads)
		if (el.second < compare_threads[min_time]) min_time = el.first;
	printf("  Best time for %d threads with time: ", static_cast<int>(min_time));
	printTime(compare_threads[min_time]);
	compare_types[std::string("Thread Half And Line Hybrid Sum with threads " + std::to_string(min_time))] = compare_threads[min_time];

	printf("\n****[ Result ]****\n");
	min_time = 0;
	std::vector<std::pair<std::string, std::chrono::nanoseconds>> compare_types_vector;
	compare_types_vector.reserve(compare_types.size());
	for (std::pair<std::string, std::chrono::nanoseconds> el : compare_types)
		compare_types_vector.emplace_back(el);
	std::sort(compare_types_vector.begin(), compare_types_vector.end(), [](auto& left, auto& right) { return left.second < right.second; });
	printf("Best time for %s with time: ", compare_types_vector[0].first.c_str());
	printTime(compare_types_vector[0].second);
}

void sortAlgorytmy(size_t elements, int min, int max) {
	printf("\n###################################################################\n");
	printf("######################### Sort Algorytmy ##########################\n");
	printf("###################################################################\n\n");

	std::unordered_map<std::string, std::chrono::nanoseconds> compare_types;
	int min_time = 0;

	printf("****[ Create Random Array ]****\n");
	Array<int> data_array;
	data_array.createRandom(elements, min, max, true);

	printf("\n****[ Insertion Sort ]****\n");
	Array<int> arr_copy;
	arr_copy.copyArray(data_array, true);
	printf("Sorting...\n");
	std::chrono::nanoseconds time = Time([&arr_copy] { arr_copy.insertionSort(); });
	if (arr_copy.size() < MAXARRAYPRINTSIZE || FORCEPRINT) {
		printf("[");
		for (int el : arr_copy)
			printf("%d, ", el);
		printf("\b\b]\n");
	}
	printf("Sorted %d elements in: ", static_cast<int>(data_array.size()));
	printTime(time);
	compare_types["Insertion Sort"] = time;

	printf("\n****[ Result ]****\n");
	min_time = 0;
	std::vector<std::pair<std::string, std::chrono::nanoseconds>> compare_types_vector;
	compare_types_vector.reserve(compare_types.size());
	for (std::pair<std::string, std::chrono::nanoseconds> el : compare_types)
		compare_types_vector.emplace_back(el);
	std::sort(compare_types_vector.begin(), compare_types_vector.end(), [](auto& left, auto& right) { return left.second < right.second; });
	printf("Best time for %s with time: ", compare_types_vector[0].first.c_str());
	printTime(compare_types_vector[0].second);
}

int nwdRecursive(int a, int b){
	a = abs(a);
	b = abs(b);
	if (b == 0) return a;
	return nwdRecursive(b, a % b);
}

int nwdNormal(int a, int b){
	a = abs(a);
	b = abs(b);
	while (a != b && b) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

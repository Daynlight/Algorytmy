#include "Base/Base.h"
#include "Arrays/Array.h"
#include <algorithm>
#include <string>
#include <functional>

void sumTest(std::string name, Array<int> arr, Array<std::pair<std::string, std::chrono::nanoseconds>> *compare_types, std::function<int(Array<int>, int)> function, int threads = 0){
	if(!threads) printf("\n****[ %s ]****\n", name.c_str());
	int sum = 0;
	std::chrono::nanoseconds time = Time([&arr, &sum, &function, &threads] { 
		sum = function(arr, threads); });
	if(!threads) {
		printf("Summed %d elements with result %d in ", static_cast<int>(arr.size()), sum);
		printTime(time);
		compare_types->emplace_back(std::pair<std::string, std::chrono::nanoseconds>(name, time));
	}
	else (*compare_types).emplace_back(std::pair<std::string, std::chrono::nanoseconds>(std::string(name + " with  " + std::to_string(threads) + " threads"), time));
}

void sortTest(std::string name, Array<int> *original_array, int tests, Array<std::pair<std::string, std::chrono::nanoseconds>> *compare_types, const std::function<void(Array<int>)> function){
	printf("\n****[ %s ]****\n", name.c_str());
	Array<int> arr_copy;
	arr_copy.copyArray(*original_array, true);
	printf("Sorting...\n");
	std::chrono::nanoseconds time = Time(tests, [&function, &arr_copy] { function(arr_copy); });
	printf("Sorted %d elements in: ", static_cast<int>(original_array->size()));
	printTime(time);
	(*compare_types).emplace_back(std::pair<std::string, std::chrono::nanoseconds>(name, time));
}

void sumTest(size_t elements, int min, int max) {
	printf("\n###################################################################\n");
	printf("######################### Sum Algorithms ##########################\n");
	printf("###################################################################\n\n");

	Array<std::pair<std::string, std::chrono::nanoseconds>> compare_types;

	printf("****[ Create Random Array ]****\n");
	Array<int> arr;
	arr.createRandom(elements, min, max, true);

	sumTest("Line Sum", arr, &compare_types, [](Array<int> arr, int threads){ return arr.lineSum(0 , arr.size() - 1); });
	for(size_t i = 0; i < 10; i++){
		sumTest("Thread Sum", arr, &compare_types, [](Array<int> arr, int threads){ return arr.threadSum(threads); }, i);
		sumTest("Hybrid Sum", arr, &compare_types, [](Array<int> arr, int threads){ return arr.hybridSum(threads); }, i);
	}

	printf("\n****[ Result ]****\n");
	std::sort(compare_types.begin(), compare_types.end(), [](auto& left, auto& right) { return left.second < right.second; });
	printf("Best time for %s with time: ", compare_types[0].first.c_str());	printTime(compare_types[0].second);
}

void sortTest(size_t elements, int min, int max, int tests = 1) {
	printf("\n###################################################################\n");
	printf("######################### Sort Algorithms ##########################\n");
	printf("###################################################################\n\n");

	Array<std::pair<std::string, std::chrono::nanoseconds>> compare_types;

	printf("****[ Create Random Array ]****\n");
	Array<int> data_array;
	data_array.createRandom(elements, min, max, true);

	sortTest("Insertion Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.insertionSort(); });
	sortTest("Selection Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.selectionSort(); });
	sortTest("Bubble Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.bubbleSort(); });
	sortTest("Merge Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.mergeSort(); });
	sortTest("Quick Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.quickSort(); });

	printf("\n****[ Result ]****\n");
	std::sort(compare_types.begin(), compare_types.end(), [](auto& left, auto& right) { return left.second < right.second; });
	printf("Best time for %s with time: ", compare_types[0].first.c_str());	printTime(compare_types[0].second);
}
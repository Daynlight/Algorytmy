#include "Base/Base.h"
#include "Arrays/Array.h"
#include <algorithm>
#include <string>
#include <functional>

void sumTest(size_t elements, int min, int max) {
	printf("\n###################################################################\n");
	printf("######################### Sum Algorithms ##########################\n");
	printf("###################################################################\n\n");

	std::unordered_map<size_t, std::chrono::nanoseconds> compare_threads;
	std::unordered_map<std::string, std::chrono::nanoseconds> compare_types;
	size_t min_time = 0;
	int sum = 0;

	printf("****[ Create Random Array ]****\n");
	Array<int> arr;
	arr.createRandom(elements, min, max, true);

	printf("\n****[ Line Sum ]****\n");
	std::chrono::nanoseconds time = 
		Time([&arr, &sum] { sum = arr.lineSum(0, arr.size()); });
	printf("Summed %d elements with result %d in ", static_cast<int>(arr.size()), sum);
	printTime(time);
	compare_types["Line Sum"] = time;

	printf("\n****[ Thread Half Parts Sum Req ]****\n");
	compare_threads.clear();
	min_time = 0;
	for (int i = 0; i < 10; i++){
		compare_threads[i] = Time([&arr, &sum, &i] { sum = arr.threadSum(i); });
		printf("Summed %d elements with result %d on %d threads in: ", static_cast<int>(arr.size()), sum, i);
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
		compare_threads[i] = Time([&arr, &i] { arr.hybridSum(i); });
		printf("Summed %d elements with result %d on %d threads in: ", static_cast<int>(arr.size()), sum, i);
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

void sortTestOne(std::string Name, Array<int> *original_array, int tests, Array<std::pair<std::string, std::chrono::nanoseconds>> *compare_types, const std::function<void(Array<int>)> function){
	printf("\n****[ %s ]****\n", Name.c_str());
	Array<int> arr_copy;
	arr_copy.copyArray(*original_array, true);
	printf("Sorting...\n");
	std::chrono::nanoseconds time = Time(tests, [&function, &arr_copy] { function(arr_copy); });
	printf("Sorted %d elements in: ", static_cast<int>(original_array->size()));
	printTime(time);
	(*compare_types).emplace_back(std::pair<std::string, std::chrono::nanoseconds>(Name, time));
}

void sortTest(size_t elements, int min, int max, int tests = 1) {
	printf("\n###################################################################\n");
	printf("######################### Sort Algorithms ##########################\n");
	printf("###################################################################\n\n");

	Array<std::pair<std::string, std::chrono::nanoseconds>> compare_types;

	printf("****[ Create Random Array ]****\n");
	Array<int> data_array;
	data_array.createRandom(elements, min, max, true);

	sortTestOne("Insertion Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.insertionSort(); });
	sortTestOne("Selection Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.selectionSort(); });
	sortTestOne("Bubble Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.bubbleSort(); });
	sortTestOne("Merge Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.mergeSort(); });
	sortTestOne("Quick Sort", &data_array, tests, &compare_types, [](Array<int> array){ array.quickSort(); });

	printf("\n****[ Result ]****\n");
	std::sort(compare_types.begin(), compare_types.end(), [](auto& left, auto& right) { return left.second < right.second; });
	printf("Best time for %s with time: ", compare_types[0].first.c_str());	printTime(compare_types[0].second);
}
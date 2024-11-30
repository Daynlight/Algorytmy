#include "Base/Base.h"
#include "Arrays/Array.h"
#include <algorithm>
#include <string>
#include <functional>

void sumTest(std::function<int(Array<int>, int)> function, Array<int> arr, int threads = 0, std::string name = "", Array<std::pair<std::string, std::chrono::nanoseconds>> *compare_types = nullptr){
	if(!threads && name != "") printf("\n****[ %s ]****\n", name.c_str());
	int sum = 0;
	std::chrono::nanoseconds time = Time([&arr, &sum, &function, &threads] { sum = function(arr, threads); });
	if(compare_types != nullptr) {
		if(!threads){ 
			printf("Summed %d elements with result %d in ", static_cast<int>(arr.size()), sum);
			printTime(time);
			compare_types->emplace_back(std::pair<std::string, std::chrono::nanoseconds>(name, time));
		}
		else compare_types->emplace_back(std::pair<std::string, std::chrono::nanoseconds>(std::string(name + " with  " + std::to_string(threads) + " threads"), time));
	}
	else {
		if(!threads){ 
			printf("Summed %d elements with result %d in ", static_cast<int>(arr.size()), sum);
			printTime(time);
		}
		else{
			printf("Summed %d elements with result %d on %d threads in ", static_cast<int>(arr.size()), sum, threads);
			printTime(time);
		}
	}
}

void sortTest(Array<int> *original_array, const std::function<void(Array<int>)> function, int tests = 1, std::string name = "", Array<std::pair<std::string, std::chrono::nanoseconds>> *compare_types = nullptr){
	if(name != "") printf("\n****[ %s ]****\n", name.c_str());
	Array<int> arr_copy;
	arr_copy.copyArray(*original_array, true);
	printf("Sorting...\n");
	std::chrono::nanoseconds time = Time(tests, [&function, &arr_copy] { function(arr_copy); });
	printf("Sorted %d elements in: ", static_cast<int>(original_array->size()));
	printTime(time);
	if(compare_types != nullptr && name != "") compare_types->emplace_back(std::pair<std::string, std::chrono::nanoseconds>(name, time));
}

void sumTest(size_t elements, int min, int max) {
	printf("\n###################################################################\n");
	printf("######################### Sum Algorithms ##########################\n");
	printf("###################################################################\n\n");

	Array<std::pair<std::string, std::chrono::nanoseconds>> compare_types;

	printf("****[ Create Random Array ]****\n");
	Array<int> arr;
	arr.createRandom(elements, min, max, true);

	sumTest([](Array<int> arr, int threads){ return arr.lineSum(0 , arr.size() - 1); }, arr, 0, "Line Sum", &compare_types);
	for(size_t i = 0; i < 10; i++){
		sumTest([](Array<int> arr, int threads){ return arr.threadSum(threads); }, arr, i, "Thread Sum", &compare_types);
		sumTest([](Array<int> arr, int threads){ return arr.hybridSum(threads); }, arr, i, "Hybrid Sum", &compare_types);
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

	sortTest(&data_array, [](Array<int> array){ array.insertionSort(); }, tests, "Insertion Sort", &compare_types);
	sortTest(&data_array, [](Array<int> array){ array.selectionSort(); }, tests, "Selection Sort", &compare_types);
	sortTest(&data_array, [](Array<int> array){ array.bubbleSort(); }, tests, "Bubble Sort", &compare_types);
	sortTest(&data_array, [](Array<int> array){ array.mergeSort(); }, tests, "Merge Sort", &compare_types);
	sortTest(&data_array, [](Array<int> array){ array.quickSort(); }, tests, "Quick Sort", &compare_types);

	printf("\n****[ Result ]****\n");
	std::sort(compare_types.begin(), compare_types.end(), [](auto& left, auto& right) { return left.second < right.second; });
	printf("Best time for %s with time: ", compare_types[0].first.c_str());	printTime(compare_types[0].second);
}

void armstrongNumbersTest(int a, int b, int tests = 1){
	printf("\n###################################################################\n");
	printf("######################### Armstrong Numbers #######################\n");
	printf("###################################################################\n\n");

	std::vector<unsigned long long> arm;
	std::chrono::nanoseconds time = Time(tests, [&arm, &a, &b ]{ arm = armstrongArray(a, b); });

	printf("[");
	for(unsigned long long el : arm)
		printf("%lld, ", el);
	printf("\b\b]\n");
	printf("Armstrong Numbers generated in: ");
	printTime(time);
}

void powTest(int a, int b, int tests = 1){
	printf("\n###################################################################\n");
	printf("######################### Pow #####################################\n");
	printf("###################################################################\n\n");

	int res = 0;
	std::chrono::nanoseconds time = Time(tests, [&res, &a, &b]{ res = powNormal(a, b); });
	printf("powNormal(%d, %d) = %d in: ", a, b, res);
	printTime(time);

	time = Time(tests, [&res, &a, &b]{ res = powRecursive(a, b); });
	printf("powRecursive(%d, %d) = %d in: ", a, b, res);
	printTime(time);
}

void nwdTests(int a, int b, int tests = 1){
	printf("\n###################################################################\n");
	printf("######################### Nwd #####################################\n");
	printf("###################################################################\n\n");

	int res = 0;
	std::chrono::nanoseconds time = Time(tests, [&res, &a, &b]{ res = nwdNormal(a, b); });
	printf("nwdNormal(%d, %d) = %d in: ", a, b, res);
	printTime(time);

	time = Time(tests, [&res, &a, &b]{ res = nwdRecursive(a, b); });
	printf("nwdRecursive(%d, %d) = %d in: ", a, b, res);
	printTime(time);
}

void factorialTests(int n, int tests = 1){
	printf("\n###################################################################\n");
	printf("######################### Factorial #####################################\n");
	printf("###################################################################\n\n");

	int res = 0;
	std::chrono::nanoseconds time = Time(tests, [&res, &n]{ res = factorialNormal(n); });
	printf("factorialNormal(%d) = %d in: ", n, res);
	printTime(time);

	time = Time(tests, [&res, &n]{ res = factorialRecursive(n); });
	printf("factorialRecursive(%d) = %d in: ", n, res);
	printTime(time);
}

void fibonacciTest(int n, int tests = 1){
	printf("\n###################################################################\n");
	printf("######################### Fibonacci #####################################\n");
	printf("###################################################################\n\n");

	int res = 0;
	std::chrono::nanoseconds time = Time(tests, [&res, &n]{ res = fibonacciNormal(n); });
	printf("fibonacciNormal(%d) = %d in: ", n, res);
	printTime(time);

	time = Time(tests, [&res, &n]{ res = fibonacciRecursive(n); });
	printf("fibonacciRecursive(%d) = %d in: ", n, res);
	printTime(time);
}
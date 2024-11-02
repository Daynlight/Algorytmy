#pragma once
#include <unordered_map>
#include <memory>
#include "Dev.h"
#include "Array.h"

void CheckClock();
void SumaAlgorytmy(int elements = 10);
void SortAlgorytmy(int elements = 10);

template<typename T>
inline ARRAY<T> ArrayCreate(int elements = 10) {
	printf("****[Create Random Array]****\n");
	ARRAY<T> arr;
	arr.reserve(elements);

	Time([&arr, &elements] {
		if (elements < 1000 || PRINT) {
			printf("[");
			for (int i = 0; i < elements; i++) {
				arr.emplace_back(Random<int>(-200, 200));
				printf("%d, ", arr[i]);
			};
			printf("\b\b]\n");
		}
		else {
			for (int i = 0; i < elements; i++)
				arr.emplace_back(Random<int>(-200, 200));
		}
		printf("Array Created in ");
	});
	printf("\nList Size: %d\n", arr.size());

	return arr;
}

template <typename T>
inline ARRAY<T> CopyArray(ARRAY<T> orgArray) {
	ARRAY<T> arr;
	Time([&orgArray, &arr] {
		arr.reserve(orgArray.size());
		for (T el : orgArray)
			arr.emplace_back(el);
		printf("Array Copied in ");
		});
	printf("\n");
	return arr;
}

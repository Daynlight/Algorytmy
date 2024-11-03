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
	PROGRESSBAR create_progress = PROGRESSBAR(elements, 50);
	printf("Creating...\n");
	Time([&arr, &elements, &create_progress] {
		if (elements < 1000 || PRINT) {
			printf("[");
			for (int i = 0; i < elements; i++) {
				arr.emplace_back(Random<int>(-200, 200));
				printf("%d, ", arr[i]);
			};
			printf("\b\b]\n");
		}
		else {
			for (int i = 0; i < elements; i++) {
				arr.emplace_back(Random<int>(-200, 200));
				create_progress.Render(i);
			}
				
		}
		printf("Array Created in ");
	});
	printf("\nList Size: %d\n", arr.size());

	return arr;
}

template <typename T>
inline ARRAY<T> CopyArray(ARRAY<T> orgArray) {
	ARRAY<T> arr;
	PROGRESSBAR copy_progress = PROGRESSBAR(orgArray.size(), 50);
	printf("Copying...\n");
	Time([&orgArray, &arr, &copy_progress] {
		int i = 0;
		arr.reserve(orgArray.size());
		for (T el : orgArray) {
			arr.emplace_back(el);
			copy_progress.Render(i++);
		}
		printf("Array Copied in ");
		});
	printf("\n");
	return arr;
}

#include "Array.h"

#include "AlgorytmsList.hpp"

template<typename T>
size_t Array<T>::size() { return data_array.size(); }

template<typename T>
void Array<T>::reserve(size_t count) { data_array.reserve(count); }

template<typename T>
void Array<T>::emplace_back(T data) { data_array.emplace_back(data); }

template<typename T>
inline T Array<T>::operator[](size_t index) { return data_array[index]; }

template<typename T>
inline std::vector<T>::iterator Array<T>::begin() { return data_array.begin(); }

template<typename T>
inline std::vector<T>::iterator Array<T>::end() { return data_array.end(); }

template<typename T>
void Array<T>::createRandom(const size_t elements, const int min, const int max, const bool progress_bar) {
	data_array.clear();
	data_array.reserve(elements);
	ProgressBar create_progress = ProgressBar(elements, 50);

	if(progress_bar) printf("Creating Random Array...\n");
	std::chrono::nanoseconds time = Time(
		[this, &elements, &create_progress, &min, &max, &progress_bar] {
		if ((elements < MAXARRAYPRINTSIZE || FORCEPRINT) && !progress_bar) {
			printf("[");
			for (int i = 0; i < elements; i++) {
				data_array.emplace_back(random(min, max));
				printf("%d, ", data_array[i]);
			};
			printf("\b\b]\n");
		}
		else {
			for (int i = 0; i < elements; i++) {
				data_array.emplace_back(random(min, max));
				if (progress_bar) create_progress.render(i);
			}
		}
		});
	if (progress_bar) printf("Array with %d elements created in ", static_cast<int>(data_array.size()));
	if (progress_bar) printTime(time);
}

template <typename T>
void Array<T>::copyArray(Array<T> &original_array, const bool progress_bar) {
	data_array.clear();
	data_array.reserve(original_array.size());
	ProgressBar copy_progress = ProgressBar(original_array.size(), 50);

	if (progress_bar) printf("Copying Array...\n");
	std::chrono::nanoseconds time = Time(
		[this, &original_array, &copy_progress, &progress_bar] {
		int i = 0;
		for (const T el : original_array) {
			data_array.emplace_back(el);
			if(progress_bar) copy_progress.render(i++);
		}
	});
	if (progress_bar) printf("Array Copied in ");
	if (progress_bar) printTime(time);
}

template <typename T>
void Array<T>::print(){
	printf("[");
	for(int el : data_array)
		printf("%d, ", el);
	printf("\b\b]");
}

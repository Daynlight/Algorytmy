#include "Array.h"

template<typename T>
size_t Array<T>::size() { return data_array.size(); }

template<typename T>
void Array<T>::reserve(size_t count) { data_array.reserve(count); }

template<typename T>
void Array<T>::emplace_back(int data) { data_array.emplace_back(data); }

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
		if ((elements < MAXARRAYPRINTSIZE || FORCEPRINTARRAY) && !progress_bar) {
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
void Array<T>::copyArray(Array<T> &orginal_array, const bool progress_bar) {
	data_array.clear();
	data_array.reserve(orginal_array.size());
	ProgressBar copy_progress = ProgressBar(orginal_array.size(), 50);

	if (progress_bar) printf("Copying Array...\n");
	std::chrono::nanoseconds time = Time(
		[this, &orginal_array, &copy_progress, &progress_bar] {
		int i = 0;
		for (const T el : orginal_array) {
			data_array.emplace_back(el);
			if(progress_bar) copy_progress.render(i++);
		}
	});
	if (progress_bar) printf("Array Copied in ");
	if (progress_bar) printTime(time);
}


template<typename T>
inline T Array<T>::lineSum(const size_t x, const size_t y) {
	T suma = 0;
	for (size_t i = x; i < y; i++)
		suma += data_array[i];
	return suma;
}

template<typename T>
T Array<T>::halfThreadSumReq(size_t thread_level) { return halfThreadSumReqFun(0, data_array.size() - 1, thread_level); }

template<typename T>
T Array<T>::halfThreadSumReqFun(const size_t x, const size_t y, size_t&thread_level) {
	if (y - x == 0) return data_array[x];
	else if (y - x == 1) return data_array[x] + data_array[y];
	else if (y - x < 0) return 0;

	T a = 0, b = 0;
	if (thread_level > 0) {
		thread_level--;
		std::future<T> eventA =
			std::async(std::launch::async, [this, &x, &y, &thread_level] { return halfThreadSumReqFun(x, (y - x) / 2 + x, thread_level); });

		b = halfThreadSumReqFun((y - x) / 2 + x + 1, y, thread_level);
		a = eventA.get();
	}
	else {
		a = halfThreadSumReqFun(x, (y - x) / 2 + x, thread_level);
		b = halfThreadSumReqFun((y - x) / 2 + x + 1, y, thread_level);
	}

	return a + b;
}

template<typename T>
T Array<T>::halfThreadAndLineSum(size_t thread_level) { return halfThreadAndLineSumFun(0, data_array.size() - 1, thread_level); }

template<typename T>
T Array<T>::halfThreadAndLineSumFun(const size_t x, const size_t y, size_t& thread_level) {
	if (y - x == 0) return data_array[x];
	else if (y - x == 1) return data_array[x] + data_array[y];
	else if (y - x < 0) return 0;

	T a = 0, b = 0;
	if (thread_level > 0) {
		thread_level--;
		std::future<T> eventA =
			std::async(std::launch::async, [this, &x, &y, &thread_level] { return halfThreadSumReqFun(x, (y - x) / 2 + x, thread_level); });

		b = halfThreadSumReqFun((y - x) / 2 + x + 1, y, thread_level);
		a = eventA.get();
	}
	else {
		a = lineSum(x, (y - x) / 2 + x);
		b = lineSum((y - x) / 2 + x + 1, y - 1);
	}

	return a + b;
}

template<typename T>
void Array<T>::insertionSort(bool progress_bar) {
	ProgressBar progress = ProgressBar(data_array.size(), 50);
	if (progress_bar) printf("Sorting...");
	for (int i = 1; i < data_array.size(); ++i) {
		int key = data_array[i];
		int j = i - 1;

		while (j >= 0 && data_array[j] > key) {
			data_array[j + 1] = data_array[j];
			j--;
		}
		data_array[j + 1] = key;
		if (!progress_bar) progress.render(i);
	}
}
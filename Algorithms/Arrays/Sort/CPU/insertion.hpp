#include "../../Array.h"

template<typename T>
void Array<T>::insertionSort(std::function<bool(T a, T b)> compare, bool progress_bar) {
	ProgressBar progress = ProgressBar(data_array.size(), 50);															// 1
	for (int i = 1; i < data_array.size(); ++i) {																						// n - 2
		int key = data_array[i];																																// 1
		int j = i - 1;																																					// 1

		while (j >= 0 && compare(data_array[j], key)) {																					// j for pessimistic j = n - 2 optimistic n = 0
			data_array[j + 1] = data_array[j];																											// 1
			j--;																																										// 1
		}
		data_array[j + 1] = key;																																// 1
		if (progress_bar) progress.render(i);																										// 1
	}
}
// 1 + (n - 2)(4 + 2*(n - 2)) = 1 + (n - 2)(2n) = 1 + 2n^2 - 4n < 1 + 2n^2 <(dla n > 1) < 3n^2 => O(n^2)
// 1 + (n - 2)(4 + 0*2) = 1 + (n - 2)(4) = 1 + 4n - 8 = 4n - 7 >(dla n > 4) n => Ω(n)
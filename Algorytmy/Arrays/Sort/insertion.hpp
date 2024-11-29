#include "../Array.h"

template<typename T>
void Array<T>::insertionSort(bool progress_bar) {
	ProgressBar progress = ProgressBar(data_array.size(), 50);
	for (int i = 1; i < data_array.size(); ++i) {
		int key = data_array[i];
		int j = i - 1;

		while (j >= 0 && data_array[j] > key) {
			data_array[j + 1] = data_array[j];
			j--;
		}
		data_array[j + 1] = key;
		if (progress_bar) progress.render(i);
	}
}
#include "../Array.h"

template <typename T>
void Array<T>::selectionSort(std::function<bool(T a, T b)> compare, bool progress_bar) {
  ProgressBar progressBar(data_array.size());
  for(int i = 0; i < data_array.size(); i++){
    int min = i;

    for(int j = i + 1; j < data_array.size(); j++)
      if(compare(data_array[min], data_array[j])) min = j;

    T temp = data_array[min];
    data_array[min] = data_array[i];
    data_array[i] = temp;

    if(progress_bar) progressBar.render(i);
  }
}
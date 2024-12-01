#include "../../Array.h"
#include <cl/opencl.h>

template <typename T>
void Array<T>::selectionGsort(std::function<bool(T a, T b)> compare){
  for(int i = 0; i < data_array.size() - 1; i++){
    int x = i;

    for(int j = i + 1; j < data_array.size(); j++)
      if(compare(data_array[x], data_array[j])) x = j;

    T temp = data_array[x];
    data_array[x] = data_array[i];
    data_array[i] = temp;
  }
}
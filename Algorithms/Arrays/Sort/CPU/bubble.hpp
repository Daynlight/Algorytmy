#include "../../Array.h"

template<typename T>
void Array<T>::bubbleSort(std::function<bool(T a, T b)> compare, bool progress_bar){
  ProgressBar progressBar(data_array.size());
  for(size_t i = 1; i < data_array.size(); i++)
    for(size_t j = 0; j < data_array.size() - i; j++){
      if(compare(data_array[j], data_array[j + 1])){
        T temp = data_array[j+1];
        data_array[j+1] = data_array[j];
        data_array[j] = temp;
      }
      if(progress_bar) 
        progressBar.render(data_array.size() - i + 1);
    }
  if(progress_bar) printf("\n");
}

#include "../Array.h"

template<typename T>
void Array<T>::bubbleSort(bool progress_bar){
  ProgressBar progressBar(data_array.size());
  for(size_t i = data_array.size() - 1; i > 2; i--)
    for(size_t j = 0; j < i - 1; j++){
      if(data_array[j] > data_array[j+1]){
        T temp = data_array[j+1];
        data_array[j+1] = data_array[j];
        data_array[j] = temp;
      }
      if(progress_bar) 
        progressBar.render(data_array.size() - i + 1);
    }
  if(progress_bar) printf("\n");
}

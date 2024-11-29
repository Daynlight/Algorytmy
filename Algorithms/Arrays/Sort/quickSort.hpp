#include "../Array.h"

template <typename T>
int Array<T>::quickSortPartition(int a, int b){
  int x = data_array[b];
  int i = a - 1;
  for (int j = a; j < b; j++){
    if(data_array[j] <= x){
      i++;
      T temp = data_array[j];
      data_array[j] = data_array[i];
      data_array[i] = temp;
    }
  }
  T temp = data_array[b];
  data_array[b] = data_array[i + 1];
  data_array[i + 1] = temp;

  return i + 1;
}

template <typename T>
void Array<T>::quickSortReq(int a, int b){
  if(b > a){
    int q = quickSortPartition(a, b);
    quickSortReq(a, q - 1);
    quickSortReq(q + 1, b);
  }
}

template <typename T>
void Array<T>::quickSort(){
  quickSortReq(0, data_array.size());
}
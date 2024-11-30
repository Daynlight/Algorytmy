#include "../Array.h"

template <typename T>
void Array<T>::mergeSortMerge(std::function<bool(T a, T b)> compare, int a, int q, int b){
  int n = q - a + 1;
  int m = b - q;
  T B[n];
  T C[m];
  for(int i = 0; i < n; i++)
    B[i] = data_array[a + i];
  for(int i = 0; i < n; i++)
    C[i] = data_array[q + i + 1];

  int i = 0, j = 0;
  while(i < n && j < m){
    if(compare(B[i], C[j])){
      data_array[a+i+j] = B[i];
      i++;
    }
    else{
      data_array[a+i+j] = C[j];
      j++;
    }
  }
  while(i < n){
    data_array[a+i+j] = B[i];
    i++;
  }
  while(j<m){
    data_array[a+i+j] = C[j];
    j++;
  }

}

template <typename T>
void Array<T>::mergeSortReq(std::function<bool(T a, T b)> compare, int a, int b){
  if(a < b){
    int q = (a+b)/2;
    mergeSortReq(compare, a, q);
    mergeSortReq(compare, q+1, b);
    mergeSortMerge(compare, a, q, b);
  }
}

template <typename T>
void Array<T>::mergeSort(std::function<bool(T a, T b)> compare) {
  mergeSortReq(compare, 0, data_array.size());
}
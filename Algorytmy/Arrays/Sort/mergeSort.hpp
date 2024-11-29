#include "../Array.h"

template <typename T>
void Array<T>::mergeSortMerge(int a, int q, int b){
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
    if(B[i] < C[j]){
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
void Array<T>::mergeSortReq(int a, int b){
  if(a < b){
    int q = (a+b)/2;
    mergeSortReq(a, q);
    mergeSortReq(q+1, b);
    mergeSortMerge(a, q, b);
  }
}

template <typename T>
void Array<T>::mergeSort() {
  mergeSortReq(0, data_array.size());
}
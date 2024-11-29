#include "Base.h"
#include "../Dev.h"

struct PowTable {
  PowTable(size_t n){
    tab[0] = 0;
    tab[1] = 1;
    for(int i = 2; i < 10; i++)
      tab[i] = powNormal(i, n);
  }
  int tab[10];
  int operator [](size_t index) { return tab[index]; }
};

int armstrongSum(int a){
  int list_count[10];
  int size = 0;
  for(int &el : list_count)
    el = 0;
  
  do{
    list_count[a%10]++;
    size++;
    a /= 10;
  } while (a!=0);

  PowTable pow_table(size);

  int sum = 0;
  for(int i = 1; i < 10; i++)
    sum += list_count[i]*pow_table[i];

  return sum;
}

std::vector<int> armstrongArray(int a, int b, int deep_level){
  std::vector<int> arm;
  if(deep_level < 1){
    for (int i = a; i < b; i++){
      int armstrong_sum = armstrongSum(i);
      if(armstrong_sum == i) arm.emplace_back(i);
    }
  }
  else{
    std::vector<int> arm1;
    std::vector<int> arm2;
    if(!THREADS){
      arm1 = armstrongArray(a, (b+a)/2, deep_level - 1);
      arm2 = armstrongArray((b+a)/2 + 1, b, deep_level - 1);
    }else{
      std::future<std::vector<int>> event = std::async(std::launch::async, [arm1, a, b, deep_level]{return armstrongArray(a, (b+a)/2, deep_level - 1);} );
      arm2 = armstrongArray((b+a)/2 + 1, b, deep_level - 1);
      arm1 = event.get();
    }

    int i = 0, j = 0;
    while (i < arm1.size() && j < arm2.size()) {
      if (arm1[i] < arm2[j]) arm.emplace_back(arm1[i++]);
      else arm.emplace_back(arm2[j++]);
    }
    while (i < arm1.size()) arm.emplace_back(arm1[i++]);
    while (j < arm2.size()) arm.emplace_back(arm2[j++]);
  }
  return arm;
}
#include "../Base.h"

struct PowTable {
  PowTable(unsigned long long n = 1){
    tab[0] = 0;
    tab[1] = 1;
    resize(&n);
  }
  void resize(const unsigned long long *n){
    for(size_t i = 2; i < 10; i++)
      tab[i] = powNormal(i, *n);
  }
  unsigned long long tab[10];
  unsigned long long operator [](const unsigned long long *index) { return tab[*index]; }
};

unsigned long long armstrongSum(unsigned long long a, PowTable *pow_table, unsigned long long *last_size){
  unsigned long long list_count[10] = {0,0,0,0,0,0,0,0,0,0};
  unsigned long long size = 0;
  do{
    list_count[a%10]++;
    size++;
    a /= 10;
  } while (a!=0);

  if(size != *last_size){
    pow_table->resize(&size);
    *last_size = size;
  }

  unsigned long long sum = 0;
  for(size_t i = 1; i < 10; i++)
    sum += list_count[i]*(*pow_table)[&i];
  return sum;
}

std::vector<unsigned long long> armstrongArray(unsigned long long a, unsigned long long b){
  std::vector<unsigned long long> arm;
  if(b-a < DIVARRAYSIZE){
    unsigned long long last_size = 1;
    PowTable pow_table(last_size);
    for (unsigned long long i = a; i < b; i++){
      unsigned long long armstrong_sum = armstrongSum(i, &pow_table, &last_size);
      if(armstrong_sum == i) arm.emplace_back(i);
    }
  }
  else{
    std::vector<unsigned long long> arm1;
    std::vector<unsigned long long> arm2;
    if(!THREADS){
      arm1 = armstrongArray(a, (b+a)/2);
      arm2 = armstrongArray((b+a)/2 + 1, b);
    }else{
      std::future<std::vector<unsigned long long>> event = std::async(std::launch::async, [arm1, a, b]
      {return armstrongArray(a, (b+a)/2);} );
      arm2 = armstrongArray((b+a)/2 + 1, b);
      arm1 = event.get();
    }

    // Merge
    unsigned long long i = 0, j = 0;
    while (i < arm1.size() && j < arm2.size()) {
      if (arm1[i] < arm2[j]) arm.emplace_back(arm1[i++]);
      else arm.emplace_back(arm2[j++]);
    }
    while (i < arm1.size()) arm.emplace_back(arm1[i++]);
    while (j < arm2.size()) arm.emplace_back(arm2[j++]);
  }

  return arm;
}


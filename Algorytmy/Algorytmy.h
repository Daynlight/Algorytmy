#pragma once
#include <unordered_map>
#include "Dev.h"
#include "Array.h"

void checkClock();
void sumaTest(size_t elements = 10, int min = -1000, int max = 1000);
void sortTest(size_t elements = 10, int min = -1000, int max = 1000);

int nwdNormal(int a, int b); // O(log(a+b))
int nwdRecursive(int a, int b); // O(log(a+b))

int powNormal(int a, int n); // O(n)
int powRecursive(int a, int n); // O(n)

int silniaNormal(int n); // O(n)
int silniaRecursive(int n); // O(n)


/*
int root(int a, int n);
int fibonachi(int n);
int firstInRange(int a, int b);
*/
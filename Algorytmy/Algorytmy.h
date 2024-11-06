#pragma once
#include <unordered_map>
#include "Dev.h"
#include "Array.h"

void checkClock();
void nwdTest(size_t count = 10, int min = -20, int max = 20);
void powTest(size_t count = 10, int min = -20, int max = 20, int maxpow = 10);
void sumaTest(size_t elements = 10, int min = -1000, int max = 1000);
void sortTest(size_t elements = 10, int min = -1000, int max = 1000);

int nwdNormal(int a, int b); // O(log(a+b))
int nwdRecursive(int a, int b); // O(log(a+b))

long long powNormal(int a, int n); // O(n)
long long powRecursive(int a, int n); // O(n)
/*
int root(int a, int n);
int silnia(int a);
int fibonachi(int n);
int firstInRange(int a, int b);
*/
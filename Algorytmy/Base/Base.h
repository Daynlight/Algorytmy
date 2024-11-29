#pragma once
#include <math.h>
#include <vector>
#include "../Dev.h"

int nwdNormal(int a, int b); // O(log(a+b))
int nwdRecursive(int a, int b); // O(log(a+b))

int powNormal(int a, int n); // O(n)
int powRecursive(int a, int n); // O(n)

int silniaNormal(int n); // O(n)
int silniaRecursive(int n); // O(n)

int fibonachiNormal(int n); // O(n)
int fibonachiRecursive(int n); // O(n)

std::vector<int> armstrongArray(int a, int b, int deep_level);

/*
int root(int a, int n);
int firstInRange(int a, int b);
*/
#pragma once
#include <math.h>
#include <vector>
#include <array>
#include "../Dev.h"

int nwdNormal(int a, int b); // O(log(a+b))
int nwdRecursive(int a, int b); // O(log(a+b))

int powNormal(int a, int n); // O(n)
int powRecursive(int a, int n); // O(n)

int factorialNormal(int n); // O(n)
int factorialRecursive(int n); // O(n)

int fibonacciNormal(int n); // O(n)
int fibonacciRecursive(int n); // O(n)

std::vector<unsigned long long> armstrongArray(unsigned long long a, unsigned long long b);

/*
int root(int a, int n);
int firstInRange(int a, int b);
*/
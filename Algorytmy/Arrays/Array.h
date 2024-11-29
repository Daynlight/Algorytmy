#pragma once
#include <vector>
#include "../Dev.h"

template<typename T>
class Array {
private:
	std::vector<T> data_array;

public:
	void createRandom(const size_t elementy = 10, const int min = -200, const int max = 200, const bool progress_bar = false);
	void copyArray(Array<T> &orginal_array, const bool progress_bar = false);
	size_t size();
	void reserve(size_t count);
	void emplace_back(int data = 0);
	// iterator
	T operator[](size_t index);
	std::vector<T>::iterator begin();
	std::vector<T>::iterator end();

public:
	// Sum
	T lineSum(const size_t x, const size_t y);
	T threadSum(size_t thread_level = 0);
	T hybridSum(size_t thread_level);
	// Search
	
	// Sort
	void insertionSort(bool progress_bar = false);

private:
	// Sum
	T halfThreadSumReqFun(const size_t x, const size_t y, size_t &thread_level);
	T halfThreadAndLineSumFun(const size_t x, const size_t y, size_t & thread_level);
};

#include "Array.hpp"
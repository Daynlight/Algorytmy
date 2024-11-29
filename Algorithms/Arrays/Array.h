#pragma once
#include <vector>
#include "../Dev.h"

template<typename T>
class Array {
private:
	std::vector<T> data_array;

public:
	void createRandom(const size_t elements = 10, const int min = -200, const int max = 200, const bool progress_bar = false);
	void copyArray(Array<T> &original_array, const bool progress_bar = false);
	size_t size();
	void reserve(size_t count);
	void emplace_back(int data = 0);
	// iterator
	T operator[](size_t index);
	std::vector<T>::iterator begin();
	std::vector<T>::iterator end();
public:
	void sort() { mergeSort(); };
	T sum(size_t thread_level = 4) { hybridSum(thread_level); };

public:
	// Sum
	T lineSum(const size_t x, const size_t y);
	T threadSum(size_t thread_level = 0);
	T hybridSum(size_t thread_level = 0);
	// Search
	
	// Sort
	void insertionSort(bool progress_bar = false);
	void bubbleSort(bool progress_bar = false);
	void selectionSort(bool progress_bar = false);
	void mergeSort();
	void quickSort();
private:
	// Sum
	T halfThreadSumReqFun(const size_t x, const size_t y, size_t &thread_level);
	T halfThreadAndLineSumFun(const size_t x, const size_t y, size_t & thread_level);
	// Sort
	void mergeSortReq(int a, int b);
	void mergeSortMerge(int a, int q, int b);
	void quickSortReq(int a, int b);
	int quickSortPartition(int a, int b);
};

#include "Array.hpp"
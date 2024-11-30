#pragma once
#include <vector>
#include "../Dev.h"
#include <functional>

template<typename T>
class Array {
private:
	std::vector<T> data_array;

public:
	void createRandom(const size_t elements = 10, const int min = -200, const int max = 200, const bool progress_bar = false);
	void copyArray(Array<T> &original_array, const bool progress_bar = false);
	void print();
	size_t size();
	void reserve(size_t count);
	void emplace_back(T data = 0);
	// iterator
	T operator[](size_t index);
	std::vector<T>::iterator begin();
	std::vector<T>::iterator end();
public:
	void sort(std::function<bool(T a, T b)> compare = [](T a, T b){ return a > b; }) { mergeSort(compare); };
	T sum(size_t thread_level = 4) { hybridSum(thread_level); };

public:
	// Sum
	T lineSum(const size_t x, const size_t y);
	T threadSum(size_t thread_level = 0);
	T hybridSum(size_t thread_level = 0);
	// Search
	
	// Sort
	void insertionSort(std::function<bool(T a, T b)> compare = [](T a, T b){ return a > b; } ,bool progress_bar = false);
	void bubbleSort(std::function<bool(T a, T b)> compare = [](T a, T b){ return a > b; }, bool progress_bar = false);
	void selectionSort(std::function<bool(T a, T b)> compare = [](T a, T b){ return a > b; }, bool progress_bar = false);
	void mergeSort(std::function<bool(T a, T b)> compare = [](T a, T b){ return a > b; });
	void quickSort(std::function<bool(T a, T b)> compare = [](T a, T b){ return a > b; });
private:
	// Sum
	T halfThreadSumReqFun(const size_t x, const size_t y, size_t &thread_level);
	T halfThreadAndLineSumFun(const size_t x, const size_t y, size_t & thread_level);
	// Sort
	void mergeSortReq(std::function<bool(T a, T b)> compare, int a, int b);
	void mergeSortMerge(std::function<bool(T a, T b)> compare, int a, int q, int b);
	void quickSortReq(std::function<bool(T a, T b)> compare, int a, int b);
	int quickSortPartition(std::function<bool(T a, T b)> compare, int a, int b);
};

#include "Array.hpp"
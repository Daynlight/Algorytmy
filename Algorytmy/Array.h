#pragma once
#include <vector>
#include "Dev.h"

template<typename T>
class ARRAY {
public:
	ARRAY();
	ARRAY(std::initializer_list<T> inArr);
	size_t size();
	void reserve(int n);
	void emplace_back(int n);
	int THREADSDEEPLEVEL = 0;
	T operator[](size_t n);
	std::vector<T>::iterator begin();
	std::vector<T>::iterator end();

	// Sum
	template<typename S>
	S HalfThreadSumReq();
	template<typename S>
	S LineSum();
	// Sort
	void InsertionSort();
private:
	int ThreadsLevel = 0;
	std::vector<T> arr;

	// Sum
	template<typename S>
	S HalfThreadSumReqFun(int x, int y);
};

#include "Array.hpp"
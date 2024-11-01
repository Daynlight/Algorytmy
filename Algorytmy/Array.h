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
	template<typename S>
	S sumaBaseReq();
	template<typename S>
	S sumaThreadReq();
	template<typename S>
	S sumaLine();
private:
	int ThreadsLevel = 0;
	std::vector<T> arr;
	template<typename S>
	S sumaBaseReqFun(int x);
	template<typename S>
	S sumaThreadReqFun(int x, int y);
};

#include "Array.hpp"
#pragma once
#include <chrono>
#include <vector>
#include <thread>

template <typename T>
class Array {
public:
	std::vector<T> arr;	
	T sumaBaseReq();
private:
	T sumaBaseReqFun(int x);
};